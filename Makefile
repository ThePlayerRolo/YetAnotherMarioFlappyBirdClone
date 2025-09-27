V=1
SRC_DIR=src
SRC_BUILD_DIR=build/src
BUILD_DIR=build
ASSETS_DIR=assets
IMAGE_FILES:=$(wildcard $(ASSETS_DIR)/*.png)
FILE_DIR=filesystem
FILE_CLEAN_DIR= filesystem/**
TTF_DIR = $(wildcard assets/*.ttf)
WAV_DIR = $(wildcard assets/*.wav)
TTF_CONV = $(addprefix filesystem/,$(notdir $(TTF_DIR:%.ttf=%.font64)))
WAV_COV = $(addprefix filesystem/,$(notdir $(WAV_DIR:%.wav=%.wav64)))
XM1_DIR = $(wildcard assets/*.xm)
XM2_DIR = $(wildcard assets/*.XM)
XM_COV = $(addprefix filesystem/,$(notdir $(XM1_DIR:%.xm=%.xm64))) \
              $(addprefix filesystem/,$(notdir $(XM2_DIR:%.XM=%.xm64))) 


SPRITE_FILES=$(subst assets,filesystem,$(IMAGE_FILES:.png=.sprite))
MKFONT_FLAGS ?= --range all --size 30 --outline 2
include $(N64_INST)/include/n64.mk

all: YAMarioFlappyBirdC.z64
.PHONY: all

OBJS =  $(BUILD_DIR)/$(SRC_DIR)/main.o $(BUILD_DIR)/$(SRC_DIR)/util.o $(BUILD_DIR)/$(SRC_DIR)/collision.o  $(BUILD_DIR)/$(SRC_DIR)/input.o  $(BUILD_DIR)/$(SRC_DIR)/mario.o   $(BUILD_DIR)/$(SRC_DIR)/game.o  $(BUILD_DIR)/$(SRC_DIR)/pipe.o $(BUILD_DIR)/$(SRC_DIR)/score.o  $(BUILD_DIR)/$(SRC_DIR)/font.o 


MKSPRITE_FLAGS = --compress 0 --format RGBA16

filesystem/%.xm64: assets/%.xm
	@mkdir -p $(dir $@)
	@echo "    [AUDIO] $@"
	@$(N64_AUDIOCONV) $(AUDIOCONV_FLAGS) -o filesystem "$<"

$(SPRITE_FILES): $(IMAGE_FILES)
	@mkdir -p $(dir $@)
	@echo "Processing file" $(notdir $(subst sprite,png,$@))
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o filesystem "$<"

filesystem/%.font64: assets/%.ttf
	@mkdir -p $(dir $@)
	@echo "    [FONT] $@"
	$(N64_MKFONT) $(MKFONT_FLAGS) -o filesystem "$<"
filesystem/%.wav64: assets/%.wav
	@mkdir -p $(dir $@)
	@echo "    [AUDIO] $@"
	$(N64_AUDIOCONV) $(AUDIOCONV_FLAGS) -o filesystem "$<"



YAMarioFlappyBirdC.z64: N64_ROM_TITLE = "YAMarioFlappyBirdC"
YAMarioFlappyBirdC.z64: N64_ED64ROMCONFIGFLAGS=-w eeprom4k
YAMarioFlappyBirdC.z64: $(SPRITE_FILES)
YAMarioFlappyBirdC.z64: $(TTF_CONV)
YAMarioFlappyBirdC.z64: $(WAV_COV)
YAMarioFlappyBirdC.z64: $(XM_COV)
YAMarioFlappyBirdC.z64: $(BUILD_DIR)/YAMarioFlappyBirdC.dfs
YAMarioFlappyBirdC.z64: $(BUILD_DIR)/$(SRC_DIR)


$(BUILD_DIR)/YAMarioFlappyBirdC.elf: $(OBJS)
$(BUILD_DIR)/YAMarioFlappyBirdC.dfs: $(wildcard $(FILE_DIR))

clean:
	rm -rf $(BUILD_DIR) *.z64
	
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
