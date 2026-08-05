class Inventory
{
public:
    class PublicItem
    {
    };

private:
    class PrivateNode
    {
    };
};

int main()
{
    Inventory::PublicItem item;
    // Inventory::PrivateNode node; // 오류

    static_cast<void>(item);
}
