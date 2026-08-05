#include <iostream>

class OutputFile
{
public:
    void Commit()
    {
        committed = true;

        std::cout << "데이터 저장 완료\n";
    }

    ~OutputFile() noexcept
    {
        if (!committed)
        {
            std::cout << "저장되지 않은 데이터 폐기\n";
        }
    }

private:
    bool committed = false;
};

int main()
{
    {
        OutputFile file;
    }

    {
        OutputFile file;

        file.Commit();
    }
}
