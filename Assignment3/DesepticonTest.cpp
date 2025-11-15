/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include <gtest/gtest.h>
#include "Desepticon.h"
#include "Engine.h"
#include "TransformerModel.h"

TEST(DesepticonTest, ConstructorInitialization){
    Engine eng(700);
    Desepticon d("Megatron",20,500,150,eng,66,true);
    EXPECT_EQ(d.getName(),"Megatron");
    EXPECT_EQ(d.getLevel(),20);
    EXPECT_EQ(d.getStrength(),500);
    EXPECT_EQ(d.getAmmo(),150);
    EXPECT_EQ(d.getEnginePower(),700);
    EXPECT_EQ(d.getDesepticonIndex(),66);
    EXPECT_TRUE(d.getIsEvil());
    EXPECT_EQ(d.getModel(),"standart");
}

TEST(DesepticonTest, SettersAndGetters){
    Engine eng(300);
    Desepticon d("Barricade",8,180,60,eng,21,false);
    d.setDesepticonIndex(999);
    d.setIsEvil(true);
    EXPECT_EQ(d.getDesepticonIndex(),999);
    EXPECT_TRUE(d.getIsEvil());
}

TEST(DesepticonTest, BaseClassMethodsWork){
    Engine eng(350);
    Desepticon d("Starscream",14,260,90,eng,3,true);
    d.setName("StarscreamV2");
    d.setLevel(15);
    d.setStrength(280);
    d.setAmmo(95);
    d.setEnginePower(1200);
    d.setModel("jet-mode");
    EXPECT_EQ(d.getName(),"StarscreamV2");
    EXPECT_EQ(d.getLevel(),15);
    EXPECT_EQ(d.getStrength(),280);
    EXPECT_EQ(d.getAmmo(),95);
    EXPECT_EQ(d.getEnginePower(),1200);
    EXPECT_EQ(d.getModel(),"jet-mode");
}

TEST(DesepticonTest, DestroyNoCrash){
    Engine eng(100);
    Desepticon d("TestCon",1,10,10,eng,0,false);
    EXPECT_NO_THROW(d.destroy());
}

TEST(DesepticonTest, EngineInteraction){
    Engine eng(450);
    Desepticon d("Shockwave",18,350,80,eng,10,true);
    EXPECT_EQ(d.getEnginePower(),450);
    d.setEnginePower(1111);
    EXPECT_EQ(d.getEnginePower(),1111);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
