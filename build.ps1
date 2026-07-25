param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$SourceFile
)

$ErrorActionPreference = "Stop"

if (-not (Test-Path -LiteralPath $SourceFile -PathType Leaf)) {
    Write-Error "Source file not found: $SourceFile"
    exit 1
}

$extension = [System.IO.Path]::GetExtension($SourceFile).TrimStart(".").ToLowerInvariant()
$filename = [System.IO.Path]::GetFileName($SourceFile)
$nameWithoutExtension = [System.IO.Path]::GetFileNameWithoutExtension($filename)
$timestamp = Get-Date -Format "yyyyMMdd_HHmmss"
$buildDir = "build"
$outputFile = Join-Path $buildDir "$($nameWithoutExtension)_$timestamp.exe"
$sourceDir = Split-Path -Parent $SourceFile
if ([string]::IsNullOrWhiteSpace($sourceDir)) {
    $sourceDir = "."
}
$inputFile = Join-Path $sourceDir "$nameWithoutExtension.in"

New-Item -ItemType Directory -Path $buildDir -Force | Out-Null

switch ($extension) {
    { $_ -in @("cpp", "cc", "cxx", "c++") } {
        & g++ -std=c++17 -Wall -Wextra -O2 $SourceFile -o $outputFile
    }
    "c" {
        & gcc -Wall -Wextra -O2 $SourceFile -o $outputFile
    }
    default {
        Write-Error "Unsupported source extension: .$extension"
        exit 1
    }
}

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

Write-Host "Built: $outputFile"
$outputPath = (Resolve-Path -LiteralPath $outputFile).Path

if (Test-Path -LiteralPath $inputFile -PathType Leaf) {
    Write-Host "Running with input: $inputFile"
    Get-Content -Raw -LiteralPath $inputFile | & $outputPath
}
else {
    Write-Host "Running without input file"
    & $outputPath
}

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}
