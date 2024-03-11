#include <array>
#include "abstractsort.h"
namespace Sorts
{
    template <typename T>
    class BinaryTreeSort : public AbstractSort<T>
    {
        enum tdirs
        {
            left = 0,
            right = 1,
            up = 2
        };

        class Node
        {
        public:
            T data;
            array<int, 3> dirs = {-1, -1, -1};
        };

    public:
        using AbstractSort<T>::AbstractSort;
        string getName() const
        {
            return "BinaryTreeSort";
        }

        void Sort(T *array, int size) override
        {
            Node *tree = new Node[size];
            tree[0].data = array[0];
            tree[0].dirs[up] = -1;

            for (int i = 1; i < size; i++)
            {
                int j = 0;
                int k;
                int dir;
                do
                {

                    k = j;
                    if (this->tester->Test(tree[j].data, array[i]) < 0)
                    {
                        dir = left;
                    }
                    else
                    {
                        dir = right;
                    }
                    j = tree[j].dirs[dir];
                } while (j != -1);
                tree[i].data = array[i];
                tree[i].dirs[up] = k;
                tree[k].dirs[dir] = i;
            }

            int dir = up;
            int i = 0;
            int j = 0;

            while (i < size)
            {
                switch (dir)
                {
                case up:
                    while (tree[j].dirs[left] != -1)
                    {
                        j = tree[j].dirs[left];
                    }
                    array[i] = tree[j].data;
                    i++;
                    if (tree[j].dirs[right] != -1)
                    {
                        j = tree[j].dirs[right];
                    }
                    else
                    {
                        if (tree[tree[j].dirs[up]].dirs[left] == j)
                        {
                            dir = left;
                        }
                        else
                        {
                            dir = right;
                        }
                        j = tree[j].dirs[up];
                    }
                    break;
                case left:
                    array[i] = tree[j].data;
                    i++;
                    if (tree[j].dirs[right] == -1)
                    {
                        if (tree[tree[j].dirs[up]].dirs[left] != j)
                        {
                            dir = right;
                        }
                        j = tree[j].dirs[up];
                    }
                    else
                    {
                        j = tree[j].dirs[right];
                        dir = up;
                    }
                    break;

                case right:
                    if (tree[tree[j].dirs[up]].dirs[left] == j)
                    {
                        dir = left;
                    }
                    j = tree[j].dirs[up];
                    break;
                default:
                    break;
                }
            }
        }
    };
};