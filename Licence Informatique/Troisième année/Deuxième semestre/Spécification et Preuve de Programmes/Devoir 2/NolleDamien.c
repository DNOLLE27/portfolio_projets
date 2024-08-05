/* NOLLE Damien - L3 Informatique */

/* Exerice 1 Question 1 */
//@ predicate cte(int a[], int c) = forall x. 0 <= x < length(a) -> a[x] == c;

/* Exerice 1 Question 2 */
//@ predicate no_dup(int a[]) = forall x, y. 0 <= x < length(a) && 0 <= y < length(a) && x < y && x == y - 1 -> a[x] != a[y];

/* Exercice 1 Quesion 4 */
//@ lemma l2: forall x[]. length(x) > 1 -> forall y. cte(x, y) -> x[0] == x[1];
//@ lemma l3: forall x[]. length(x) > 1 -> x[0] == x[1] -> !no_dup(x);

/* Exerice 1 Question 3 */
//@ lemma l1: forall x[]. length(x) > 1 -> forall y. cte(x, y) -> !no_dup(x);

/* Exerice 1 Question 5
    Les lemmes de la question 4 doivent être placé avant le lemme de la question 3 pour aider à la démonstration de ce dernier.
*/

/* Exercice 2 Question 1*/
int carre(int x)
/* Exercice 2 Question 2*/
/*@ requires x >= 0; 
ensures result == x*x; */
{
    int i = 0;
    int c = 0;
    
    while (i < x)
    /* Exercice 2 Question 3 et 4*/
    /*@ invariant c == i*i && i <= x;
    variant x - i; */
    {
        c = c + 2*i + 1;
        i = i + 1;
    }
    
    return c;
}

/* Exercice 3 Question 1 */
int max(int t[], int n)
/* Exercice 3 Question 2 */
/*@ requires n > 0 && length(t) > 0;
ensures forall x. 0 <= x < n <= length(t) && x != result -> t[x] <= t[result]; */
{
    int i = 0;
    int iMax = 0;
    
    while (i < n)
    /* Exercice 3 Question 3 */
    /*@ invariant i <= n ; 
    variant n - i; */
    {
        if (t[i] > t[iMax])
        {
            iMax = i;
        }
        
        i = i + 1;
    }
    
    return iMax;
}

/* Exercice 4 Question 1 */
int recherche_dichotomique(int t[], int x, int n)
/* Exercice 4 Question 2 */
/*@ requires 0 <= n <= length(t) && forall i, j. 0 <= i < j < n -> t[i] <= t[j]; 
    ensures (forall k. 0 <= k < result -> t[k] <= x) && (forall k. result <= k < n -> t[k] > x);
    */
{
    int min = -1;
    int max = n - 1;
    int m;
    
    while (min != max)
    /* Exercice 4 Question 3 */
    /*@ invariant (forall j. 0 <= j <= min -> t[j] <= x) && (forall j. max + 1 <= j < n -> t[j] > x); 
    variant max - min; */
    {
        m = (min + max + 1) / 2;
        
        if (t[m] <= x)
        {
            min = m;
        }
        else
        {
            max = m - 1;
        }
    }
    
    int posx = min + 1;
    
    return posx;
}

