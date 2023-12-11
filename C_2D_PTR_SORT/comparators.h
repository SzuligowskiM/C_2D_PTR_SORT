#if !defined(_comparators_h_)
#define _comparators_h_

int comp_min(const int *ptr1, const int *ptr2, int width);
int comp_max(const int *ptr1, const int *ptr2, int width);
int comp_sum(const int *ptr1, const int *ptr2, int width);
int sort_rows(int** tab, int width, int height, int (*func)(const int*,const int*, int));
void delete_tab(int** tab, int height);
#endif
