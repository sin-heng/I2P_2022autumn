#include <stdio.h>
#include <string.h>

char str[1000005];
int sub[1000005];
int type[100005], id[100005], A[100005], B[100005], C[100005];
int alphabet[26];

int main()
{
    int Q;
    char c1, c2;
    for (int i = 0; i < 1000005; ++i) sub[i] = -1;
    scanf("%s", str);
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &type[i]);
        if (type[i] == 1) {
            scanf(" %c %c", &c1, &c2);
            A[i] = c1;
            B[i] = c2;
        }
        else {
            scanf(" %d %c", &id[i], &c2);
            C[i] = c2;
        }
    }
    for (int i = 0; i < 26; ++i)
        alphabet[i] = i + 'a';
    for (int i = Q - 1; i >= 0; --i) {
        if (type[i] == 1)
            alphabet[A[i] - 'a'] = alphabet[B[i] - 'a'];
        else if (sub[id[i]] == -1) {
            sub[id[i]] = i;
            C[i] = alphabet[C[i] - 'a'];
        }
    }
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        if(sub[i] != -1) printf("%c", (char)C[sub[i]]);
        else printf("%c", (char)alphabet[str[i] - 'a']);
    printf("\n");

    return 0;
}