# XY_MCU_Lib
A lightweight and reusable MCU development library for STM32 and embedded systems.


简介

个人嵌入式开发库，主要用于单片机平台的模块化开发与代码复用。

目标是常用嵌入式软件组件，使不同项目之间可以快速迁移与复用代码，提高开发效率与代码规范性。

最终目标是覆盖嵌入式开发中约 90% 的常用基础组件与通用算法模块，为快速开发与项目复用提供统一的基础框架。

 统一嵌入式开发接口风格
 屏蔽底层芯片差异（HAL / 寄存器）
 提高代码复用率
 支持后续扩展到 RTOS / Linux / IoT 平台


架构分层

当前采用基础分层设计：

* **BSP层**：硬件相关封装（GPIO / UART / SPI / I2C 等）
* **Hardware层**：外设驱动（传感器 / 存储器 / 显示等）
* **Middleware层**：通信与协议（MQTT / JSON / Modbus 等）
* **Utils层**：通用工具（RingBuffer / CRC / Log / Timer）
* **App层**：具体应用逻辑

---

## 当前已支持模块

### BSP

* GPIO（完成）
* UART（简易完成）
* ADC (准备中)
* DAC (准备中)
* Delay（计划中）

### Hardware

* LED（完成）
* KEY（简易完成,后续添加双击等事件）
* OTFTLCD (进行中)
* 后续安排


### Utils

* 


---

## 未来规划

* 完成完整 BSP 层封装
* 添加 UART DMA + RingBuffer 框架
* 实现统一日志系统（Log模块）
* 添加 MQTT 通信中间件
* 支持 FreeRTOS
* 扩展 Linux / RK3588 应用层结构

---

## 使用说明

本库为个人开发库，模块会持续更新与重构，不保证 API 长期完全稳定。



