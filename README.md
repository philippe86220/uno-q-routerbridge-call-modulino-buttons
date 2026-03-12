# UNO Q – RouterBridge `call()` Example with Modulino Buttons

This example demonstrates a practical use of `Bridge.call()` on the Arduino UNO Q using the **Modulino Buttons** module.

The goal is to illustrate an important architectural concept of the **RouterBridge system**:  
the **MCU can request a service from the MPU exactly when it needs it**.

---

# Concept

In this example:

1. A **button press** is detected on the **MCU** using the Modulino Buttons module.
2. When the event occurs, the MCU requests the **Linux system time** from the **MPU**.
3. The request is performed using:

Bridge.call("get_system_time")

4. The MPU executes a Python function and returns the result.
5. The MCU receives and prints the returned value.

This demonstrates a **request/response interaction** between the MCU and the MPU.

---

# Why `Bridge.call()` is useful

Some information could be sent periodically from the MPU to the MCU (for example system time).  
However, this does not replace the following model:

**the MCU requests the information only when an event occurs.**

In this architecture:

- the **event originates on the MCU**
- the **MCU decides the moment of the request**
- the **MPU provides the requested service**
- the **result is returned to the MCU**

This is the principle of a **Remote Procedure Call (RPC)**.

The key idea is:

> `Bridge.call()` allows the MCU to request a service from the MPU exactly when the MCU needs it.

---

# notify() vs call()

RouterBridge provides two complementary mechanisms.

### notify()

MCU → MPU

Used to **publish an event or data** without expecting a response.

Example:

distance = 85 mm

---

### call()

MCU → MPU → response

Used when the MCU **requests a service and expects a result**.

Example:

get_system_time

---

# Example architecture

Modulino Button press
        │
        ▼
MCU detects event
        │
        ▼
Bridge.call("get_system_time")
        │
        ▼
MPU executes Python function
        │
        ▼
Time returned to MCU
        │
        ▼
Printed on Monitor

---

# Python service provided by the MPU

The MPU registers a function that can be called remotely.

Bridge.provide("get_system_time", get_system_time)

This function returns the Linux system time.

---

# Purpose of this example

This repository shows a simple but realistic scenario where:

- the **event occurs on the MCU**
- the **MCU controls the timing of the request**
- the **MPU provides a higher-level Linux/Python service**

It demonstrates how `Bridge.call()` enables **on-demand service requests** in the UNO Q hybrid architecture.

---

# Hardware used

- Arduino **UNO Q**
- **Modulino Buttons**
- USB connection to host running **Arduino App Lab**

---

# Related concepts

- RouterBridge
- RPC (Remote Procedure Call)
- MCU ↔ MPU hybrid architecture
- Event-driven systems
