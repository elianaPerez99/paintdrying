#include "pch.h"
#include "Drier.h"
#include "Paint.h"
#include <fstream>
#include <string>

TEST(DryingCorrectly, TestDrying)
{
	Drier drier;
	//testing for all three descriptions
	ASSERT_EQ(drier.printOutNormalDescription(), "The paint is wet.");
	ASSERT_EQ(drier.printOutNormalDescription(), "The paint is moist.");
	ASSERT_EQ(drier.printOutNormalDescription(), "The paint is dry.");
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
	ASSERT_EQ(drier.printOutCustomDescription(), "The paint is very wet. It glimmers in the sunlight.");
	ASSERT_EQ(drier.printOutCustomDescription(), "The paint is slightly wet. It is shiny.");
	ASSERT_EQ(drier.printOutCustomDescription(), "The paint is moist.");
	ASSERT_EQ(drier.getCustomPaint().getColor(), "yellow");
}

TEST(PaintObject, TestDefaultPaintObject)
{
	Paint paint;
	ASSERT_TRUE(paint.getDryability() == 1);
	ASSERT_EQ(paint.getColor(), "white");
	ASSERT_EQ(paint.getDescription(0), "The paint is wet.");
	paint.incrementIndex();
	ASSERT_EQ(paint.getDescriptionAtCurrentIndex(), "The paint is moist.");
}

TEST(PaintObject, TestCustomPaintObject)
{
	Paint paint(slowDry, "yellow");
	ASSERT_TRUE(paint.getDryability() == 2);
	ASSERT_EQ(paint.getColor(), "yellow");
	ASSERT_EQ(paint.getDescription(0), "The paint is very wet. It glimmers in the sunlight.");
	paint.incrementIndex();
	ASSERT_EQ(paint.getDescriptionAtCurrentIndex(), "The paint is slightly wet. It is shiny.");
}

TEST(DryingBackwards, TestDrying)
{
	Drier drier;
	//testing for all three descriptions
	ASSERT_EQ(drier.printOutBackwardsDescription(), "The paint is dry.");
	ASSERT_EQ(drier.printOutBackwardsDescription(), "The paint is moist.");
	ASSERT_EQ(drier.printOutBackwardsDescription(), "The paint is wet.");
}

int main(int argc, char* argv[]) {
	Drier drier;
	drier.getInput();
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}