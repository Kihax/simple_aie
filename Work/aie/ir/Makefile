.PHONY: all  i0_kernels.rule clean

ifeq ($(XILINX_VITIS_AIETOOLS),)
XILINX_VITIS_AIETOOLS:=${XILINX_VITIS}/aietools
endif
ifeq ($(CARDANO_AIE_ARCH_MODEL_DIR),)
CARDANO_AIE_ARCH_MODEL_DIR := ${XILINX_VITIS_AIETOOLS}/data/versal_prod/lib
endif
XCHESSCC := xchesscc

INCLUDE_PATH := -I ../../.. -I ${XILINX_VITIS_AIETOOLS}/include -I /home/killian/projects/simple_aie/. -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime_cxx/libcxx-lite/include -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime_cxx/libs/libcxx-16/include-lite -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime/include

all:  i0_kernels.rule

i0_kernels.rule:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-Xclang,-chess-only-info-critical-passes,-g -D_LIBCPP_LIMITS_H -D_LIBCPP_STDIO_H -D_LIBCPP_STDINT_H -D__AIENGINE__ -D__AIE_ARCH__=10 -D__LOCK_FENCE_MODE__=0 -DAIE_OPTION_SCALAR_FLOAT_ON_VECTOR  -I /home/killian/projects/simple_aie ${INCLUDE_PATH} /home/killian/projects/simple_aie/kernels.cc -o i0_kernels.ll

clean:
	rm -rf  i0_kernels.ll