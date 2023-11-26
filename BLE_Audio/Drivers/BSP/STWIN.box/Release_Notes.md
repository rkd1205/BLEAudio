---
pagetitle: Release Notes for STEVAL-STWINBX1 Board Drivers 
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for <mark>STEVAL-STWINBX1</mark> Board Drivers
Copyright &copy; 2023  STMicroelectronics\
    
[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>


# Purpose

The BSP (Board Specific Package) STEVAL-STWINBX1 Board Drivers are based on the HAL drivers and provide
a set of high level APIs relative to the hardware components and features in the evaluation board for a 
given STM32 processor

The BSP drivers allow a quick access to the boards’ services using high level APIs and without any specific 
configuration as the link with the HAL and the external components is done in intrinsic within the drivers. 

Here is the list of references to user documents:

- [DB4598](https://www.st.com/resource/en/data_brief/steval-stwinbx1.pdf) : STWIN.box - SensorTile Wireless Industrial Node Development Kit
- [UM2965](https://www.st.com/resource/en/user_manual/um2965-getting-started-with-the-stevalstwinbx1-sensortile-wireless-industrial-node-development-kit-stmicroelectronics.pdf) : Getting started with the STEVAL-STWINBX1 SensorTile wireless industrial node development kit
- [STM32Cube](https://www.st.com/stm32cube) : STM32Cube
:::

::: {.col-sm-12 .col-lg-8}
# Update History

::: {.collapse}
<input type="checkbox" id="collapse-section3" checked aria-hidden="true">
<label for="collapse-section3" aria-hidden="true">__v1.0.2 / 13-Mar-23__</label>
<div>			

## Main Changes

### Patch release

- Added missing WIFI_LPTIM_IC_CaptureCallback in STWIN.box_wifi
- Fixed typos in STWIN.box_conf_template and STWIN.box

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section2" checked aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">__v1.0.1 / 14-Feb-23__</label>
<div>			

## Main Changes

### Patch release

- Fixed typos in STWIN.box_conf_template
- Removed sensor-related macros from STWIN.box.h

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" checked aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">__v1.0.0 / 2-Dec-22__</label>
<div>			

## Main Changes

### First official release

- First official release

</div>
:::

:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on **STEVAL-STWINBX1** ,
visit: [www.st.com/stwinbox](https://www.st.com/stwinbox)
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>