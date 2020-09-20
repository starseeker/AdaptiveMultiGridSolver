#include <amgs/MyMiscellany.h>
#include <amgs/Allocator.h>

int main()
{
    Allocator<int> anAllocator;
    anAllocator.set(10);
    auto element = anAllocator.newElements();
    anAllocator.reset();
    return 0;
}
