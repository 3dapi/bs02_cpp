#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class SceneNode
    : public std::enable_shared_from_this<SceneNode>
{
public:
    explicit SceneNode(std::string name)
        : name(std::move(name))
    {
    }

    ~SceneNode()
    {
        std::cout << name << " 소멸\n";
    }

    void AddChild(
        const std::shared_ptr<SceneNode>& child
    )
    {
        child->parent = shared_from_this();
        children.push_back(child);
    }

    std::shared_ptr<SceneNode> Parent() const
    {
        return parent.lock();
    }

private:
    std::string name;
    std::vector<std::shared_ptr<SceneNode>> children;
    std::weak_ptr<SceneNode> parent;
};

int main()
{
    auto parent =
        std::make_shared<SceneNode>("parent");

    auto child =
        std::make_shared<SceneNode>("child");

    parent->AddChild(child);

    std::cout << std::boolalpha;
    std::cout << static_cast<bool>(
        child->Parent()
    ) << '\n';
}
