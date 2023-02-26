#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    int info;
    struct linked_list * next_p;
    struct linked_list * prev_p;
} l_list;

l_list *l_list_init(int item);
l_list *add_list(l_list *l_p, int item);
l_list *del_list(l_list *l_p);
l_list * del_all(l_list *l_p);
long long computeExpression(l_list *l_p);

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    l_list *list_p;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (i == 0) {
            list_p = l_list_init(a);
        } else {
            list_p = add_list(list_p, a);
        }
    }
    printf("%lld\n",computeExpression(list_p));
    list_p = del_all(list_p);
    printf("%d\n", list_p);
    return 0;
}

l_list *l_list_init(int item) {
    l_list *l_p;
    l_p = malloc(sizeof(struct linked_list));
    *l_p = (l_list) {.info = item,
            .next_p = NULL,
            .prev_p = NULL
    };
    return l_p;
};

l_list *add_list(l_list *l_p, int item) {
    struct linked_list *node_p;
    node_p = malloc(sizeof(struct linked_list));
    node_p->info = item;
    l_p->next_p = node_p;
    node_p->prev_p = l_p;
    return node_p;
}

l_list *del_list(l_list *l_p) {
    size_t node_p = (size_t) l_p->prev_p;
    if (!l_p) free(l_p);
    return node_p;
}

l_list * del_all(l_list *l_p) {
    while (l_p->prev_p != 0) {
        l_p = del_list(l_p);
    }
    l_p = del_list(l_p);
    return l_p;
}
long long computeExpression(l_list *l_p) {
    long long result = 1;
    l_list *last_l = l_p;
    while (l_p->prev_p != 0) {
        l_p = l_p->prev_p;
    }
    while (l_p->next_p != 0) {
        result *= l_p->info + l_p->next_p->info + 2*last_l->info;
        l_p = l_p->next_p;
        last_l = last_l->prev_p;
    }
    return result;
}
