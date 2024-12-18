#include <iostream>
#include <string>

// variables
std::string name;
// classes
// create a plyer class
class player{
    public:
    std::string name;
    std::string backstory;
    int hp;
    int damage;
    std::string inventory[10];
    player(std::string name, std::string backstory, int hp, int damage){
        this-> name = name;
        this-> backstory = backstory;
        this-> hp = hp;
        this-> damage = damage;
    }

    void attack();
    void take_damage();
    void add_item();
};
// create enemy class
class enemy{
    public:
    std::string name;
    std::string loot;
    int hp;
    enemy(std::string name, std::string loot, int hp){
        this-> name = name;
        this-> loot = loot;
        this-> hp = hp;
    }
    void attack();
    void take_damage();
    void drop_loot();
};
// create a weapon class
class weapon{
    public:
    std::string name;
    std::string description;
    int damage;
    int attack_speed;
    weapon(std::string name, std::string description, int damage, int attack_speed){
        this-> name = name;
        this-> description = description;
        this-> damage = damage;
        this-> attack_speed = attack_speed;
    }
    void attack();
    void inspect();

};
// create an armor class
class armor{
    public:
    std::string name;
    std::string description;
    int defence;
    armor(std::string name, std::string description, int defence){
        this-> name = name;
        this-> description = description;
        this-> defence = defence;
    }

};
// creaet a room
class room{
    public:
    std::string name;
    std::string description;
    room(std::string name, std::string description){
        this-> name = name;
        this-> description = description;
    }
    void enter();
    void leave();
};
// functions
void character_creator();

int main(){
    int choise_1;
    int choise_2;
    // make the character
    character_creator();
    std::cout << "you wake up in a ruined house at the edge of a cliff. your body feels stiff from the cold wind coming through the broken walls.\n"
              << "1_leave the house.\n"
              << "2_go to the basement\n"
              << "make a choise(1/2)?: \n";
    std::cin >> choise_1;
    room house("", "");
    room basement("", "");
    room littleRock_Pines("", "");
    switch(choise_1){
        case 1 :
        basement = room("{basement}\n", " you walk down into the basement. you can hear a sound of rough breating around the corner\n");
        std::cout << basement.name << "\n";
        std::cout << basement.description << "\n";

        std::cout << "1_go check out the sound\n";
        std::cout << "2_leave the basement\n";
        std::cout << "make a choise(1/2)?: ";
        std::cin >> choise_2;
        switch(choise_2){
            case 1 :
            house = room("{house}","you go back to the main hall");
        }
        case 2 :
        littleRock_Pines = room("littlerock pines", "a dark forest coverd in snow");
    }
    
    return 0;
}
void character_creator(){
    int class_choise;
    std::cout << "******************************\n";
    std::cout << "*    choose your class(1/2/3): \n";
    std::cout << "******************************\n";
    std::cout << "*class one\n"
              << "*name: knight\n"
              << "*backstory: a knight banishd from the order\n"
              << "*health: 150\n"
              << "*damage: 50\n"
              << "******************************\n";

    std::cout << "*class two\n"
              << "*name: thief\n"
              << "*backstory: a petty thief from the slums\n"
              << "*health: 100\n"
              << "*damage: 75\n"
              << "******************************\n";

    std::cout << "*class three\n"
              << "*name: mage\n"
              << "*backstory: an aspiring young mage from the tower\n"
              << "*health: 50\n"
              << "*damage: 100\n"
              << "******************************\n";
    std::cin >> class_choise;

    player player_1("", "", 0, 0);

    switch (class_choise){
        case 1 :
        player_1 = player("knight", "a knight banishd from the order", 150, 50);
        break;
        case 2 :
        player_1 = player("thief", "a petty thief from the slums", 100, 75);
        break;
        case 3 :
        player_1 = player("wizard", "an aspiring young mage from the tower", 50, 100);
        break;
        default:
        std::cout << "Invalid class choice." << std::endl;
        break;
    }
}