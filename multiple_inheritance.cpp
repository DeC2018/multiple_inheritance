#include <iostream>

struct unitid {
    explicit unitid(int i = 0) : id(i) {}
    int id;
};

struct Unit {
    Unit(unitid id, int hp) : id_(id), hp_(hp) {}
    virtual unitid id() const { return id_; }
    virtual int hp() const { return hp_; }
private:
    unitid id_;
    int    hp_;
};
struct Elf : Unit {
    explicit Elf(unitid id, int hp) : Unit(id, hp) {}
private:
    int dataElf;
};
struct Archer : Unit {
    explicit Archer(unitid id, int hp) : Unit(id, hp) {}
private:
    int dataArcher;
};
struct ElfArcher : Elf, Archer {
    ElfArcher(unitid id, int hp) : Elf(id, hp), Archer(id, hp) {};

    unitid id() const { return Elf::id(); }
    int hp() const { return Elf::hp(); }
};

int main() {
    ElfArcher* elfArcher = new ElfArcher((unitid)12, 0);
    Elf* elf = elfArcher;
    Archer* archer = elfArcher;

    std::cout << "elfArcher: " << &elfArcher << std::endl;
    std::cout << "as Elf   : " << &elf << std::endl;
    std::cout << "as Archer: " << &archer << std::endl;

    return 0;
}