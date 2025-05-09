V=1
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
IMAGES_DIR=images
IMAGE_FILES:=$(wildcard $(IMAGES_DIR)/*.png)
SPRITES_DIR=filesystem
SPRITE_FILES=$(subst images,filesystem,$(IMAGE_FILES:.png=.sprite))
include $(N64_INST)/include/n64.mk

all: FirstProject.z64
.PHONY: all
OBJS =  $(BUILD_DIR)/$(SRC_DIR)/main.o  $(BUILD_DIR)/$(SRC_DIR)/mario.o 


MKSPRITE_FLAGS = --compress 0 --format RGBA16



$(SPRITE_FILES): $(IMAGE_FILES)
	@mkdir -p $(dir $@)
	@echo "Processing file" $(notdir $(subst sprite,png,$@))
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o filesystem "$<"



FirstProject.z64: N64_ROM_TITLE = "First Project"
FirstProject.z64: $(SPRITE_FILES)
FirstProject.z64: $(BUILD_DIR)/FirstProject.dfs
FirstProject.z64: $(BUILD_DIR)/$(SRC_DIR)



$(BUILD_DIR)/FirstProject.elf: $(OBJS)
$(BUILD_DIR)/FirstProject.dfs: $(wildcard $(SPRITES_DIR))

clean:
	rm -rf $(BUILD_DIR) *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
