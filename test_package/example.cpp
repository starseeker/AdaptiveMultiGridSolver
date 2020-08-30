#include <afes/MyMiscellany.h>
#include <afes/Allocator.h>

int main()
{
    Allocator<int> anAllocator;
    anAllocator.set(10);
    auto element = anAllocator.newElements();
    anAllocator.reset();
    return 0;
}
