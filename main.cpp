#include <bits/stdc++.h>
#include "run.h"
using namespace std;

int main()
{
    srand(time(NULL));
    node *root;
    root = init();
    run(root, root);
    system("pause");
    return 0;
}
