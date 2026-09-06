# C++ 코딩테스트 암기용 소스 모음

목표: 코드를 눈으로만 보지 말고, VS Code에서 직접 타이핑하고 `./build.sh <file>`로 실행하면서 문법과 패턴을 손에 익힌다.

## 추천 학습 순서

1. `00_basic/01_pointer_reference.cpp`
2. `00_basic/02_function_and_loop.cpp`
3. `01_stl/01_vector_string.cpp`
4. `01_stl/02_stack_queue_deque.cpp`
5. `01_stl/03_map_set.cpp`
6. `01_stl/04_priority_queue.cpp`
7. `02_linked_list/01_node_basic.cpp`
8. `02_linked_list/02_dummy_node.cpp`
9. `02_linked_list/03_reverse_list.cpp`
10. `03_sort_search/01_sort.cpp`
11. `03_sort_search/02_binary_search.cpp`
12. `03_sort_search/03_binary_search_boundaries.cpp`
13. `04_recursion_backtracking/01_recursion.cpp`
14. `04_recursion_backtracking/02_backtracking.cpp`
15. `05_graph/01_graph_representation.cpp`
16. `05_graph/02_dfs.cpp`
17. `05_graph/03_bfs.cpp`
18. `05_graph/04_grid_dfs_bfs.cpp`
19. `05_graph/05_iterative_dfs.cpp`
20. `05_graph/06_multi_source_bfs.cpp`
21. `06_tree/01_tree_traversal.cpp`
22. `06_tree/02_tree_bfs.cpp`
23. `06_tree/03_tree_dfs_return_value.cpp`
24. `07_patterns/01_two_pointers.cpp`
25. `07_patterns/02_sliding_window.cpp`
26. `07_patterns/03_prefix_sum.cpp`
27. `07_patterns/04_greedy.cpp`
28. `07_patterns/05_variable_sliding_window.cpp`
29. `07_patterns/06_fast_slow_pointer.cpp`
30. `07_patterns/07_monotonic_stack.cpp`
31. `07_patterns/08_merge_intervals.cpp`
32. `08_dp/01_dp_basic.cpp`
33. `08_dp/02_knapsack.cpp`
34. `08_dp/03_memoization.cpp`
35. `08_dp/04_2d_dp.cpp`
36. `09_advanced/01_union_find.cpp`
37. `09_advanced/02_dijkstra.cpp`
38. `09_advanced/03_topological_sort.cpp`
39. `09_advanced/04_topological_dp.cpp`
40. `09_advanced/05_trie.cpp`

## 암기 방법

각 파일은 다음 순서로 연습한다.

1. 처음 1회: 주석까지 읽으면서 그대로 타이핑
2. 두 번째: 파일을 닫고 핵심 로직만 다시 작성
3. 세 번째: 변수명을 바꿔서 다시 작성
4. 네 번째: 예제 입력값을 바꿔서 결과 예측 후 실행
5. 다음 날: 빈 파일에서 핵심 패턴을 5분 안에 재작성

## 특히 외워야 하는 핵심 패턴

- 포인터: `p->member`, `p = p->next`, `nullptr`
- vector: `push_back`, `size`, range-for
- stack: `push`, `top`, `pop`
- queue: `push`, `front`, `pop`
- map/set: `find`, `count`, `insert`, `[]`
- 연결 리스트: 순회, dummy node, reverse
- 정렬: `sort(begin, end)`
- 이진 탐색: 정확한 값 탐색과 `[left, right)` 경계 탐색
- DFS/BFS
- 격자 탐색: 방향 배열 + 범위 검사 + 다중 시작 BFS
- Tree DFS의 반환값과 레벨 단위 BFS
- Two Pointer / 고정·가변 Sliding Window / Prefix Sum
- Fast/Slow Pointer / Monotonic Stack / 구간 병합
- Bottom-up DP / Memoization / 2차원 DP
- Union-Find / Dijkstra / Topological Sort / Trie

## 문제 풀이 전에 보는 기준

- 문법이 헷갈릴 때: `00_basic`, `01_stl`
- 연결 리스트 문제: `02_linked_list`, `07_patterns/06_fast_slow_pointer.cpp`
- 정렬·탐색 문제: `03_sort_search`, `07_patterns/08_merge_intervals.cpp`
- 완전 탐색 문제: `04_recursion_backtracking`
- 그래프·격자 문제: `05_graph`, `09_advanced/01_union_find.cpp`부터 `04_topological_dp.cpp`
- 트리 문제: `06_tree`
- 연속 구간 문제: `07_patterns/01_two_pointers.cpp`부터 `05_variable_sliding_window.cpp`
- DP 문제: `08_dp`

예제를 통째로 외우기보다 종료 조건, 상태의 의미, 반복문 범위와 자료형을 설명할 수 있는지 확인한다.
