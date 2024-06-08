#pragma once

#include <iostream>
#include <QVector>
#include <QTextStream>

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";

class TreeNode
{
public:
    QString data;
    int key;
    int height;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const QString &data, int key) : data(data), key(key), height(1), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    TreeNode *root;

    TreeNode *insert(TreeNode *node, const QString &data, int key)
    {
        if (!node)
        {
            return new TreeNode(data, key);
        }

        if (key < node->key)
        {
            node->left = insert(node->left, data, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, data, key);
        }
        else
        {
            return node;
        }

        return balanceNode(node);
    }

    TreeNode *findMin(TreeNode *node) const
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *remove(TreeNode *node, int key)
    {
        if (!node)
            return nullptr;
        if (key < node->key)
        {
            node->left = remove(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
        }
        else
        {
            if (!node->left)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }
            TreeNode *temp = findMin(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = remove(node->right, temp->key);
        }
        return balanceNode(node);
    }

    TreeNode *find(TreeNode *node, int key) const
    {
        if (!node || node->key == key)
            return node;
        if (key < node->key)
            return find(node->left, key);
        return find(node->right, key);
    }

    void preOrder(TreeNode *node, QTextStream &stream) const
    {
        if (!node)
            return;
        stream << node->data << " (" << node->key << ") ";
        preOrder(node->left, stream);
        preOrder(node->right, stream);
    }

    void inOrder(TreeNode *node, QTextStream &stream) const
    {
        if (!node)
            return;
        inOrder(node->left, stream);
        stream << node->data << " (" << node->key << ") ";
        inOrder(node->right, stream);
    }

    void postOrder(TreeNode *node, QTextStream &stream) const
    {
        if (!node)
            return;
        postOrder(node->left, stream);
        postOrder(node->right, stream);
        stream << node->data << " (" << node->key << ") ";
    }

    void storeInOrder(TreeNode *node, QVector<TreeNode *> &nodes)
    {
        if (!node)
            return;
        storeInOrder(node->left, nodes);
        nodes.append(node);
        storeInOrder(node->right, nodes);
    }

    int height(TreeNode *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(TreeNode *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(TreeNode *node)
    {
        if (node)
        {
            node->height = 1 + std::max(height(node->left), height(node->right));
        }
    }

    TreeNode *rotateRight(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    TreeNode *rotateLeft(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    TreeNode *balanceNode(TreeNode *node)
    {
        if (!node)
            return nullptr;

        updateHeight(node);

        int balance = getBalance(node);

        // Левый случай
        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return rotateRight(node);
        }

        // Левый правый случай
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Правый случай
        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return rotateLeft(node);
        }

        // Правый левый случай
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    QString treeStruct(TreeNode const *node, bool high = true, std::vector<std::string> const &lpref = std::vector<std::string>(), std::vector<std::string> const &cpref = std::vector<std::string>(), std::vector<std::string> const &rpref = std::vector<std::string>(), bool root = true, bool left = true, std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr)
    {
        if (!node)
            return "";
        typedef std::vector<std::string> VS;
        auto VSCat = [](VS const &a, VS const &b)
        { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
        if (root)
            lines = std::make_shared<std::vector<VS>>();
        if (node->left)
            treeStruct(node->left, high, VSCat(lpref, high ? VS({" ", " "}) : VS({" "})), VSCat(lpref, high ? VS({ch_ddia, ch_ver}) : VS({ch_ddia})), VSCat(lpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), false, true, lines);
        auto sval = std::to_string(node->key);
        size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
        for (size_t i = 0; i < sval.size(); ++i)
            lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref
                                                            : rpref,
                                   {std::string(1, sval[i])}));
        if (node->right)
            treeStruct(node->right, high, VSCat(rpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), VSCat(rpref, high ? VS({ch_rddia, ch_ver}) : VS({ch_rddia})), VSCat(rpref, high ? VS({" ", " "}) : VS({" "})), false, false, lines);
        if (root)
        {
            VS out;
            for (size_t l = 0;; ++l)
            {
                bool last = true;
                std::string line;
                for (size_t i = 0; i < lines->size(); ++i)
                    if (l < (*lines).at(i).size())
                    {
                        line += lines->at(i)[l];
                        last = false;
                    }
                    else
                        line += " ";
                if (last)
                    break;
                out.push_back(line);
            }

            QString result;

            for (size_t i = 0; i < out.size(); ++i)
            {
                result += QString::fromStdString(out[i]) + "\n";
            }

            return result;
        }
        else
        {
            return "";
        }
    }

    void countLeavesAtEachLevel(TreeNode *node, int level, QVector<int> &levels) const
    {
        if (!node)
            return;
        if (levels.size() <= level)
        {
            levels.append(0);
        }
        if (!node->left && !node->right)
        {
            levels[level]++;
        }
        else
        {
            countLeavesAtEachLevel(node->left, level + 1, levels);
            countLeavesAtEachLevel(node->right, level + 1, levels);
        }
    }

    void clear(TreeNode *node)
    {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { clear(root); }

    void insert(const QString &data, int key)
    {
        root = insert(root, data, key);
    }

    bool find(int key) const
    {
        TreeNode *result = find(root, key);
        return result ? true : false;
    }

    void remove(int key)
    {
        root = remove(root, key);
    }

    void clear()
    {
        
    }

    QString preOrderTraversal() const
    {
        QString result;
        QTextStream stream(&result);
        preOrder(root, stream);
        return result;
    }

    QString inOrderTraversal() const
    {
        QString result;
        QTextStream stream(&result);
        inOrder(root, stream);
        return result;
    }

    QString postOrderTraversal() const
    {
        QString result;
        QTextStream stream(&result);
        postOrder(root, stream);
        return result;
    }

    int countLeavesAtEachLevel(QVector<int> &levels) const
    {
        levels.clear();
        countLeavesAtEachLevel(root, 0, levels);
        return levels.size();
    }

    const QString drawTree()
    {
        if (root)
            return treeStruct(root, true);
    }
};  