/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __SOC_MEDIATEK_MT8167_MMSYS_H
#define __SOC_MEDIATEK_MT8167_MMSYS_H

#define MT8167_DISP_REG_CONFIG_DISP_OVL0_MOUT_EN	0x030
#define MT8167_DISP_REG_CONFIG_DISP_DITHER_MOUT_EN	0x038
#define MT8167_DISP_REG_CONFIG_DISP_COLOR0_SEL_IN	0x058
#define MT8167_DISP_REG_CONFIG_DISP_DSI0_SEL_IN		0x064
#define MT8167_DISP_REG_CONFIG_DISP_RDMA0_SOUT_SEL_IN	0x06c

#define MT8167_DITHER_MOUT_EN_RDMA0			0x1
#define MT8167_RDMA0_SOUT_DSI0				0x2
#define MT8167_DSI0_SEL_IN_RDMA0			0x1

static const struct mtk_mmsys_routes mt8167_mmsys_routing_table[] = {
	{
		DDP_COMPONENT_OVL0, DDP_COMPONENT_COLOR0,
		MT8167_DISP_REG_CONFIG_DISP_OVL0_MOUT_EN, OVL0_MOUT_EN_COLOR0,
	}, {
		DDP_COMPONENT_DITHER0, DDP_COMPONENT_RDMA0,
		MT8167_DISP_REG_CONFIG_DISP_DITHER_MOUT_EN, MT8167_DITHER_MOUT_EN_RDMA0
	}, {
		DDP_COMPONENT_OVL0, DDP_COMPONENT_COLOR0,
		MT8167_DISP_REG_CONFIG_DISP_COLOR0_SEL_IN, COLOR0_SEL_IN_OVL0
	}, {
		DDP_COMPONENT_RDMA0, DDP_COMPONENT_DSI0,
		MT8167_DISP_REG_CONFIG_DISP_DSI0_SEL_IN, MT8167_DSI0_SEL_IN_RDMA0
	}, {
		DDP_COMPONENT_RDMA0, DDP_COMPONENT_DSI0,
		MT8167_DISP_REG_CONFIG_DISP_RDMA0_SOUT_SEL_IN, MT8167_RDMA0_SOUT_DSI0
	},
};

#endif /* __SOC_MEDIATEK_MT8167_MMSYS_H */