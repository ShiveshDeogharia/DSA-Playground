#include "queue_ds.h"
namespace dsa{
void QueueDS::menu() {
    while (true) {
        std::cout << "\n— Queue Operations —\n1. Enqueue\n2. Dequeue\n3. Front\n4. Size\n0. Return\n> ";
        int c; std::cin >> c;
        if (c == 0) break;
        switch (c) {
            case 1: {
                int v; std::cout << "Value: "; std::cin >> v;
                q.push(v);
                break;
            }
            case 2: {
                if (q.empty()) std::cout << "Empty\n";
                else {
                    std::cout << q.front() << " dequeued\n";
                    q.pop();
                }
                break;
            }
            case 3: {
                if (q.empty()) std::cout << "Empty\n";
                else std::cout << "Front = " << q.front() << "\n";
                break;
            }
            case 4: {
                std::cout << "Size = " << q.size() << "\n";
                break;
            }
            default:
                std::cout << "Invalid\n";
        }
    }
}
}