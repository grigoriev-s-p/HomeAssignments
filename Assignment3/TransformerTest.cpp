/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include <gtest/gtest.h>
#include "Autobot.h"
#include "Engine.h"
#include "TransformerModel.h"

TEST(TransformerTest, ConstructorInitialization) {
    Engine eng(500);
    Autobot t("Optimus", 10, 200, 50, &eng, 1, true);
    EXPECT_EQ(t.getName(), "Optimus");
    EXPECT_EQ(t.getLevel(), 10);
    EXPECT_EQ(t.getStrength(), 200);
    EXPECT_EQ(t.getAmmo(), 50);
    EXPECT_EQ(t.getEnginePower(), 500);
    EXPECT_EQ(t.getModel(), "standart");
    EXPECT_EQ(t.getAutobotIndex(), 1);
    EXPECT_TRUE(t.getIsPrime());
}

TEST(TransformerTest, SettersAndGetters) {
    Engine eng(150);
    Autobot t("Bumblebee", 5, 120, 20, &eng, 2, false);
    t.setName("NewName");
    t.setLevel(7);
    t.setStrength(180);
    t.setAmmo(99);
    t.setAutobotIndex(5);
    t.setIsPrime(true);

    EXPECT_EQ(t.getName(), "NewName");
    EXPECT_EQ(t.getLevel(), 7);
    EXPECT_EQ(t.getStrength(), 180);
    EXPECT_EQ(t.getAmmo(), 99);
    EXPECT_EQ(t.getAutobotIndex(), 5);
    EXPECT_TRUE(t.getIsPrime());
}

TEST(TransformerTest, EnginePowerChange) {
    Engine eng(300);
    Autobot t("Megatron", 9, 250, 80, &eng, 3, false);
    EXPECT_EQ(t.getEnginePower(), 300);
    t.setEnginePower(900);
    EXPECT_EQ(t.getEnginePower(), 900);
}

TEST(TransformerTest, ModelChange) {
    Engine eng(200);
    Autobot t("Starscream", 6, 170, 60, &eng, 4, true);
    EXPECT_EQ(t.getModel(), "standart");
    t.setModel("jet-mode");
    EXPECT_EQ(t.getModel(), "jet-mode");
}

TEST(TransformerTest, FireAndTransformNoCrash) {
    Engine eng(100);
    Autobot t("Test", 1, 10, 10, &eng, 0, false);
    EXPECT_NO_THROW(t.Fire());
    EXPECT_NO_THROW(t.Transform());
    EXPECT_NO_THROW(t.Fight());
}
TEST(TransformerTest, OutputOperator) {
    Engine eng(100);
    Autobot t("Optimus", 10, 200, 50, &eng, 1, true);
    std::ostringstream oss;
    oss << t;
    std::string output = oss.str();

    EXPECT_NE(output.find("Optimus"), std::string::npos);
    EXPECT_NE(output.find("autobotIndex=1"), std::string::npos);
    EXPECT_NE(output.find("isPrime=true"), std::string::npos);
}