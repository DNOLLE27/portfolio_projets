/*@
predicate I(int min, int max, int t[], int n, int x) 
= forall j. (0 <= j <= min -> t[j] <= x) && forall j. (max + 1 <= j < n -> t[j] > x);
predicate postcond1 (int posx, int min, int max, int t[], int n, int x) 
= (min == max && I(min, max, t, n, x)) -> (posx == min + 1 || posx == max + 1);
predicate precond (int n, int t[]) 
= (n >= 0 && n < length(t)) && forall i, j. ((0 <= i < n && 0 <= j < n && i < j)
-> t[i] <= t[j]);
predicate postcond2 (int posx, int x, int n, int t[]) 
= forall k. (0 <= k < posx -> t[k] <= x) && forall k. (posx <= k < n -> t[k] > x);
*/