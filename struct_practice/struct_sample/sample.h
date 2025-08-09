#ifndef __SAMPLE_H__
#define __SAMPLE_H__

typedef signed int I1_SAMPLE1_INNER_ELEMENT1;
typedef unsigned int I1_SAMPLE1_INNER_ELEMENT2;
typedef signed char I1_SAMPLE1_INNER_ELEMENT3;
typedef unsigned char I1_SAMPLE1_INNER_ELEMENT4;

typedef struct I1_Sample1 {
    I1_SAMPLE1_INNER_ELEMENT1 I1_S1_I_E1;
    I1_SAMPLE1_INNER_ELEMENT2 I1_S1_I_E2;
} I1_Sample1;

typedef struct I1_Sample2 {
    I1_SAMPLE1_INNER_ELEMENT3 I1_S1_I_E3;
    I1_SAMPLE1_INNER_ELEMENT4 I1_S1_I_E3;
} I1_Sample2;

typedef struct Sample {
    I1_Sample1 I1_S1;
    I1_Sample2 I1_S2;
} Sample;


#endif