#include <iostream>

using namespace std;

class HuffNode
{
public:
    char *character; //we use char pointer to make it nullable
    string code = "";
    int frequency;
    HuffNode *leftChild;
    HuffNode *rightChild;
};
enum CodeAppend
{
    left,
    right,
    null
};

void prefix(HuffNode *tree, CodeAppend cta);

int main(int argc, char const *argv[])
{
    HuffNode *tree = new HuffNode();
    tree->leftChild = new HuffNode();
    tree->leftChild->leftChild = new HuffNode();
    tree->leftChild->leftChild->leftChild = new HuffNode();
    tree->leftChild->leftChild->leftChild->leftChild = new HuffNode();
    char e = 'e';
    tree->leftChild->leftChild->leftChild->leftChild->character = &e;

    cout << "fuck";
    prefix(tree, CodeAppend::null);

    return 0;
}

void prefix(HuffNode *tree, CodeAppend cta)
{
    if (tree == NULL)
    {
        return;
    }

    if (cta == CodeAppend::right)
    {   
        tree->code.append("1");
    }
    else if (cta == CodeAppend::left)
    {
        cout<<"left";
        tree->code.append("0");
    }
    prefix(tree->leftChild, CodeAppend::left);
    prefix(tree->rightChild, CodeAppend::right);

    cout << tree->character << tree->code << "\n";
}
