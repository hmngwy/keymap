# Get qmk path using the qmk cli
# qmk_home := ${HOME}/qmk_firmware
qmk_home := $(shell qmk config user.qmk_home | cut -d= -f2)

# Set `keyboard_id` to select keyboard base
#keyboard_id   := crkbd/rev1/common
keymap_name   := mailmanpat
keyboard_path := $(shell echo ${keyboard_id} | cut -d "/" -f1)

# Set `use_docker=1` to use Docker for building
ifeq (${use_docker},1)
	make := ./util/docker_build.sh
else
	make := make
endif

debug:
	@echo ${keyboard_path}:${keyboard_id}:${keymap_name}

help:
	@echo "Try 'make c' (compile) or 'make f' (flash)"

ref:
	@grep -E '[│─┄]' keymap.c | less

compile: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}

flash: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}:flash

${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/%: ./%
	cp $< $@

mkdir:
	@mkdir -p ${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}

push: \
	mkdir \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/config.h \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/rules.mk \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/keymap.c

# Don't delete these intermediate files
.PRECIOUS: %/keymap.c

c: compile
f: flash
r: ref