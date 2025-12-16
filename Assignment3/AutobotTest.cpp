/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include <gtest/gtest.h>
#include "Autobot.h"
#include "Engine.h"
#include "TransformerModel.h"
#include <sstream>

TEST(AutobotTest, ConstructorInitialization)
{
    Engine eng(600);
    Autobot a("Optimus Prime", 15, 300, 100, &eng, 1, true);
    EXPECT_EQ(a.getName(), "Optimus Prime");
    EXPECT_EQ(a.getLevel(), 15);
    EXPECT_EQ(a.getStrength(), 300);
    EXPECT_EQ(a.getAmmo(), 100);
    EXPECT_EQ(a.getEnginePower(), 600);
    EXPECT_EQ(a.getAutobotIndex(), 1);
    EXPECT_TRUE(a.getIsPrime());
    EXPECT_EQ(a.getModel(), "standard");
}

TEST(AutobotTest, DefaultConstructor)
{
    Autobot a;
    EXPECT_EQ(a.getName(), "DefaultAutobot");
    EXPECT_EQ(a.getLevel(), 1);
    EXPECT_EQ(a.getStrength(), 50);
    EXPECT_EQ(a.getAmmo(), 10);
    EXPECT_EQ(a.getAutobotIndex(), 0);
    EXPECT_FALSE(a.getIsPrime());
    EXPECT_EQ(a.getModel(), "standard");
}

TEST(AutobotTest, SettersAndGetters)
{
    Engine eng(300);
    Autobot a("Bee", 7, 150, 40, &eng, 12, false);
    a.setAutobotIndex(99);
    a.setIsPrime(true);
    EXPECT_EQ(a.getAutobotIndex(), 99);
    EXPECT_TRUE(a.getIsPrime());
}

TEST(AutobotTest, BaseClassMethodsWork)
{
    Engine eng(200);
    Autobot a("Ironhide", 8, 220, 70, &eng, 5, false);
    a.setName("Ironhide V2");
    a.setLevel(9);
    a.setStrength(230);
    a.setAmmo(80);
    a.setEnginePower(900);
    a.setModel("combat-mode");
    EXPECT_EQ(a.getName(), "Ironhide V2");
    EXPECT_EQ(a.getLevel(), 9);
    EXPECT_EQ(a.getStrength(), 230);
    EXPECT_EQ(a.getAmmo(), 80);
    EXPECT_EQ(a.getEnginePower(), 900);
    EXPECT_EQ(a.getModel(), "combat-mode");
}

TEST(AutobotTest, VirtualMethods)
{
    Engine eng(200);
    Autobot a("Optimus", 10, 200, 50, &eng, 1, true);
    EXPECT_NO_THROW(a.Fight());
    EXPECT_NO_THROW(a.Fire());
    EXPECT_NO_THROW(a.Transform());
}

TEST(AutobotTest, ScanDoesNotCrash)
{
    Engine eng(100);
    Autobot a("TestBot", 1, 10, 10, &eng, 0, false);
    EXPECT_NO_THROW(a.scan());
}

TEST(AutobotTest, EngineInteraction)
{
    Engine eng(150);
    Autobot a("Ratchet", 10, 180, 60, &eng, 3, false);
    EXPECT_EQ(a.getEnginePower(), 150);
    a.setEnginePower(777);
    EXPECT_EQ(a.getEnginePower(), 777);
}

TEST(AutobotTest, OutputOperator)
{
    Engine eng(100);
    Autobot a("Bumblebee", 5, 120, 20, &eng, 2, false);
    std::ostringstream oss;
    oss << a;
    std::string output = oss.str();

    EXPECT_NE(output.find("Bumblebee"), std::string::npos);
}
