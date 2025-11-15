/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include <gtest/gtest.h>
#include "Jettroid.h"
#include "Engine.h"
#include "TransformerModel.h"

TEST(JettroidTest, ConstructorInitialization){
    Engine eng(500);
    Jettroid j("SkyJet",12,220,70,eng,999,true);
    EXPECT_EQ(j.getName(),"SkyJet");
    EXPECT_EQ(j.getLevel(),12);
    EXPECT_EQ(j.getStrength(),220);
    EXPECT_EQ(j.getAmmo(),70);
    EXPECT_EQ(j.getEnginePower(),500);
    EXPECT_EQ(j.getMoney(),999);
    EXPECT_TRUE(j.getIsRich());
    EXPECT_EQ(j.getModel(),"standart");
}

TEST(JettroidTest, SettersAndGetters){
    Engine eng(200);
    Jettroid j("Trader",6,140,30,eng,50,false);
    j.setMoney(777);
    j.setIsRich(true);
    EXPECT_EQ(j.getMoney(),777);
    EXPECT_TRUE(j.getIsRich());
}

TEST(JettroidTest, BaseClassMethodsWork){
    Engine eng(300);
    Jettroid j("Aero",10,180,55,eng,100,false);
    j.setName("AeroX");
    j.setLevel(11);
    j.setStrength(190);
    j.setAmmo(60);
    j.setEnginePower(800);
    j.setModel("flight-mode");
    EXPECT_EQ(j.getName(),"AeroX");
    EXPECT_EQ(j.getLevel(),11);
    EXPECT_EQ(j.getStrength(),190);
    EXPECT_EQ(j.getAmmo(),60);
    EXPECT_EQ(j.getEnginePower(),800);
    EXPECT_EQ(j.getModel(),"flight-mode");
}

TEST(JettroidTest, TradeNoCrash){
    Engine eng(100);
    Jettroid j("TestJet",1,10,10,eng,0,false);
    EXPECT_NO_THROW(j.trade());
}

TEST(JettroidTest, EngineInteraction){
    Engine eng(250);
    Jettroid j("JetPower",15,240,90,eng,300,false);
    EXPECT_EQ(j.getEnginePower(),250);
    j.setEnginePower(999);
    EXPECT_EQ(j.getEnginePower(),999);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
