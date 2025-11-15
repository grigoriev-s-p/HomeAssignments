/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include <gtest/gtest.h>
#include "Transformer.h"
#include "Engine.h"
#include "TransformerModel.h"

TEST(TransformerTest, ConstructorInitialization) {
    Engine eng(500);
    Transformer t("Optimus", 10, 200, 50, eng);
    EXPECT_EQ(t.getName(), "Optimus");
    EXPECT_EQ(t.getLevel(), 10);
    EXPECT_EQ(t.getStrength(), 200);
    EXPECT_EQ(t.getAmmo(), 50);
    EXPECT_EQ(t.getEnginePower(), 500);
    EXPECT_EQ(t.getModel(), "standart");
}

TEST(TransformerTest, SettersAndGetters) {
    Engine eng(150);
    Transformer t("Bumblebee", 5, 120, 20, eng);
    t.setName("NewName");
    t.setLevel(7);
    t.setStrength(180);
    t.setAmmo(99);
    EXPECT_EQ(t.getName(), "NewName");
    EXPECT_EQ(t.getLevel(), 7);
    EXPECT_EQ(t.getStrength(), 180);
    EXPECT_EQ(t.getAmmo(), 99);
}

TEST(TransformerTest, EnginePowerChange) {
    Engine eng(300);
    Transformer t("Megatron", 9, 250, 80, eng);
    EXPECT_EQ(t.getEnginePower(), 300);
    t.setEnginePower(900);
    EXPECT_EQ(t.getEnginePower(), 900);
}

TEST(TransformerTest, ModelChange) {
    Engine eng(200);
    Transformer t("Starscream", 6, 170, 60, eng);
    EXPECT_EQ(t.getModel(), "standart");
    t.setModel("jet-mode");
    EXPECT_EQ(t.getModel(), "jet-mode");
}

TEST(TransformerTest, FireAndTransformNoCrash) {
    Engine eng(100);
    Transformer t("Test", 1, 10, 10, eng);
    EXPECT_NO_THROW(t.Fire());
    EXPECT_NO_THROW(t.Transform());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
