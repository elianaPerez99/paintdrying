#include "pch.h"
#include "Drier.h"
#include "Paint.h"
#include <fstream>

/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}*/

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(DryingCorrectly, TestDrying)
{
	Drier drier;
	//testing for all three descriptions
	ASSERT_TRUE(drier.printOutNormalDescription() == "The paint is wet.");
	ASSERT_TRUE(drier.printOutNormalDescription() == "The paint is moist.");
	ASSERT_TRUE(drier.printOutNormalDescription() == "The paint is dry.");
}

TEST(FileWorks, TestCustomPaint)
{
	Drier drier;
	string falseName = "file.txt";
	string workingName = "customPaint.txt";

	//making sure that it will only read correct files
	ASSERT_FALSE(drier.createPaintFromFile(falseName));
	ASSERT_TRUE(drier.createPaintFromFile(workingName));

	//making sure that paint was actually made correctly
	ASSERT_TRUE(drier.printOutNormalDescription() == "The is very wet. It glimmers in the sunlight.");
	ASSERT_TRUE(drier.printOutNormalDescription() == "The paint is slightly wet. It is shiny.");
	ASSERT_TRUE(drier.printOutNormalDescription() == "The paint is moist.");
}