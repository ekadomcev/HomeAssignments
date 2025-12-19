// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include <gtest/gtest.h>
#include "../src/transformer.h"
#include "../src/autobot.h"
#include "../src/decepticon.h"
#include "../src/minicon.h"
#include "../src/weapon.h"
#include "../src/pilot.h"
#include <vector>
#include <sstream>

using namespace tf;

// ==================== Weapon Tests ====================

TEST(WeaponTest, Initialization)
{
    Weapon w(50, 10);
    EXPECT_EQ(w.getDamage(), 50);
    EXPECT_EQ(w.getAmmo(), 10);
}

TEST(WeaponTest, Fire)
{
    Weapon w(50, 10);
    w.fire();
    EXPECT_EQ(w.getAmmo(), 9);
}

TEST(WeaponTest, FireEmpty)
{
    Weapon w(50, 1);
    w.fire();
    w.fire(); // Should not go negative
    EXPECT_EQ(w.getAmmo(), 0);
}

TEST(WeaponTest, Reload)
{
    Weapon w(50, 5);
    w.reload(10);
    EXPECT_EQ(w.getAmmo(), 15);
}

// ==================== Pilot Tests ====================

TEST(PilotTest, Initialization)
{
    Pilot p("Spike");
    EXPECT_EQ(p.getName(), "Spike");
}

TEST(PilotTest, Command)
{
    Pilot p("Spike");
    p.command(); // Should not crash
}

// ==================== Autobot Tests ====================

TEST(AutobotTest, DefaultConstructor)
{
    Autobot a;
    EXPECT_EQ(a.getLevel(), 0);
    EXPECT_EQ(a.getEmpathy(), 0);
    EXPECT_FALSE(a.isGuardianMode());
}

TEST(AutobotTest, ParameterizedConstructor)
{
    Weapon w(50, 10);
    Autobot a(5, 200, 100, w, 90, true);
    EXPECT_EQ(a.getLevel(), 5);
    EXPECT_EQ(a.getStrength(), 200);
    EXPECT_EQ(a.getFuel(), 100);
    EXPECT_EQ(a.getEmpathy(), 90);
    EXPECT_TRUE(a.isGuardianMode());
}

TEST(AutobotTest, Getters)
{
    Weapon w(50, 10);
    Autobot a(1, 100, 50, w, 80, false);
    EXPECT_EQ(a.getLevel(), 1);
    EXPECT_EQ(a.getStrength(), 100);
    EXPECT_EQ(a.getFuel(), 50);
    EXPECT_EQ(a.getEmpathy(), 80);
    EXPECT_FALSE(a.isGuardianMode());
}

TEST(AutobotTest, PilotAssociation)
{
    Weapon w(50, 10);
    Autobot a(1, 100, 50, w, 90, true);
    Pilot p("Spike");

    a.setPilot(&p);
    EXPECT_EQ(a.getPilot()->getName(), "Spike");
}

TEST(AutobotTest, RollOut)
{
    Autobot a;
    a.rollOut(); // Should print and not crash
}

TEST(AutobotTest, Transform)
{
    Autobot a;
    a.transform(); // Pure virtual override, should print
}

TEST(AutobotTest, OpenFire)
{
    Autobot a;
    a.openFire(); // Virtual override
}

TEST(AutobotTest, UltraMove)
{
    Autobot a;
    a.ultraMove(); // Virtual override
}

TEST(AutobotTest, Move)
{
    Autobot a;
    EXPECT_TRUE(a.move());
}

TEST(AutobotTest, Jump)
{
    Autobot a;
    EXPECT_TRUE(a.jump());
}

TEST(AutobotTest, Fire)
{
    Autobot a;
    EXPECT_TRUE(a.fire());
}

TEST(AutobotTest, OutputStream)
{
    Weapon w(50, 10);
    Autobot a(1, 100, 50, w, 90, true);
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "Autobot(Level: 1, Empathy: 90)");
}

// ==================== Decepticon Tests ====================

TEST(DecepticonTest, DefaultConstructor)
{
    Decepticon d;
    EXPECT_EQ(d.getLevel(), 0);
    EXPECT_EQ(d.getMalice(), 0);
    EXPECT_FALSE(d.isStealthMode());
}

TEST(DecepticonTest, ParameterizedConstructor)
{
    Weapon w(30, 10);
    Decepticon d(10, 500, 200, w, 100, true);
    EXPECT_EQ(d.getLevel(), 10);
    EXPECT_EQ(d.getStrength(), 500);
    EXPECT_EQ(d.getFuel(), 200);
    EXPECT_EQ(d.getMalice(), 100);
    EXPECT_TRUE(d.isStealthMode());
}

TEST(DecepticonTest, Scheme)
{
    Decepticon d;
    d.scheme(); // Should print
}

TEST(DecepticonTest, Transform)
{
    Decepticon d;
    d.transform();
}

TEST(DecepticonTest, OpenFire)
{
    Decepticon d;
    d.openFire();
}

TEST(DecepticonTest, UltraMove)
{
    Decepticon d;
    d.ultraMove();
}

TEST(DecepticonTest, OutputStream)
{
    Weapon w(30, 10);
    Decepticon d(10, 500, 200, w, 100, true);
    std::stringstream ss;
    ss << d;
    EXPECT_EQ(ss.str(), "Decepticon(Level: 10, Malice: 100)");
}

// ==================== MiniCon Tests ====================

TEST(MiniConTest, DefaultConstructor)
{
    MiniCon m;
    EXPECT_EQ(m.getLevel(), 0);
    EXPECT_EQ(m.getSizeClass(), 0);
    EXPECT_FALSE(m.isLinked());
}

TEST(MiniConTest, ParameterizedConstructor)
{
    Weapon w(5, 2);
    MiniCon m(1, 20, 10, w, 2, true);
    EXPECT_EQ(m.getLevel(), 1);
    EXPECT_EQ(m.getStrength(), 20);
    EXPECT_EQ(m.getFuel(), 10);
    EXPECT_EQ(m.getSizeClass(), 2);
    EXPECT_TRUE(m.isLinked());
}

TEST(MiniConTest, PowerLink)
{
    MiniCon m;
    EXPECT_FALSE(m.isLinked());
    m.powerLink();
    EXPECT_TRUE(m.isLinked());
    m.powerLink();
    EXPECT_FALSE(m.isLinked());
}

TEST(MiniConTest, Transform)
{
    MiniCon m;
    m.transform();
}

TEST(MiniConTest, OpenFire)
{
    MiniCon m;
    m.openFire();
}

TEST(MiniConTest, UltraMove)
{
    MiniCon m;
    m.ultraMove();
}

TEST(MiniConTest, OutputStream)
{
    Weapon w(5, 2);
    MiniCon m(1, 20, 10, w, 2, false);
    std::stringstream ss;
    ss << m;
    EXPECT_EQ(ss.str(), "MiniCon(Level: 1, SizeClass: 2)");
}

// ==================== Virtual Method Tests via Base Pointer ====================

TEST(VirtualMethodTest, TransformViaBasePointer)
{
    Weapon w(50, 10);
    Autobot a(1, 100, 50, w, 90, true);
    Transformer* t = &a;
    t->transform(); // Should call Autobot::transform
}

TEST(VirtualMethodTest, OpenFireViaBasePointer)
{
    Weapon w(50, 10);
    Decepticon d(10, 500, 200, w, 100, false);
    Transformer* t = &d;
    t->openFire(); // Should call Decepticon::openFire
}

TEST(VirtualMethodTest, UltraMoveViaBasePointer)
{
    Weapon w(5, 2);
    MiniCon m(1, 20, 10, w, 1, false);
    Transformer* t = &m;
    t->ultraMove(); // Should call MiniCon::ultraMove
}

// ==================== Vector of 9 Polymorphic Objects ====================

TEST(HierarchyTest, VectorOfNinePointers)
{
    Weapon w(10, 10);
    std::vector<Transformer*> bots;

    // Create 9 objects (3 of each type)
    for (int i = 0; i < 3; ++i)
    {
        bots.push_back(new Autobot(i, 100, 50, w, 50, true));
        bots.push_back(new Decepticon(i, 200, 50, w, 100, false));
        bots.push_back(new MiniCon(i, 20, 10, w, 1, false));
    }

    EXPECT_EQ(bots.size(), 9u);

    // Iterate and call virtual methods via base pointer
    for (Transformer* bot : bots)
    {
        bot->transform();
        bot->openFire();
        bot->ultraMove();
    }

    // Clean up
    for (Transformer* bot : bots)
    {
        delete bot;
    }
}

// ==================== Main ====================

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
