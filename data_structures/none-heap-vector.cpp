#include <vector>
#include <stdexcept>

class MaxHeap
{
private:
    std::vector<int> heap;

    void siftUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent])
            {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else
                break;
        }
    }

    void siftDown(int index)
    {
        int size = heap.size();
        while (2 * index + 1 < size)
        {
            int left = 2 * index + 1, right = 2 * index + 2;
            int largest = left;

            if (right < size && heap[right] > heap[left])
                largest = right;

            if (heap[largest] > heap[index])
            {
                std::swap(heap[largest], heap[index]);
                index = largest;
            }
            else
                break;
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    bool pop()
    {
        if (heap.empty())
            return false;

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        siftDown(0);
        return true;
    }

    int top()
    {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        return heap[0];
    }

    bool empty() { return heap.empty(); }
    int size() { return heap.size(); }
};