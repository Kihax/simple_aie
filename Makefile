PLATFORM = /home/killian/Xilinx/2025.2/Vitis/base_platforms/xilinx_vck190_base_202520_1/xilinx_vck190_base_202520_1.xpfm
WORK_DIR = Work

all: compile simulate

compile:
	aiecompiler --target=hw \
	            --platform=$(PLATFORM) \
	            --include="." \
	            --workdir=$(WORK_DIR) \
	            main.cpp

simulate:
	aiesimulator --pkg-dir=$(WORK_DIR)

clean:
	rm -rf $(WORK_DIR) aiesimulator_output .AIE_SIM_CMD_history *.log vitis_*