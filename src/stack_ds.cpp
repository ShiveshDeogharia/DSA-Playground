#include "stack_ds.h"
namespace dsa{
void StackDS::menu() {
    while (true) {
        std::cout << "\n— Stack Operations —\n1. Push\n2. Pop\n3. Top\n4. Size\n0. Return\n> ";
        int c; std::cin >> c;
        if (c == 0) break;
        switch (c) {
            case 1: {
                int v; std::cout << "Value: "; std::cin >> v; st.push(v);
                break;
            }
            case 2: {
                if (st.empty()) std::cout << "Empty\n";
                else {
                    std::cout << st.top() << " popped\n";
                    st.pop();
                }
                break;
            }
            case 3: {
                if (st.empty()) std::cout << "Empty\n";
                else std::cout << "Top = " << st.top() << "\n";
                break;
            }
            case 4: {
                std::cout << "Size = " << st.size() << "\n";
                break;
            }
            default:
                std::cout << "Invalid\n";
        }
    }
}
}