class Player
{
public:
    void Update();
    void ProcessInput();
    void Move();
    void Attack();
    void TakeDamage(int damage);
    void PlaySound();
    void SaveToFile();
    void LoadFromFile();
    void DrawHud();
    void WriteCombatLog();

private:
    int hp = 100;
    int attackPower = 20;
    int score = 0;
};

int main()
{
    Player player;
    (void)player;
}
