# 📱 akernel-spes (Custom Android Kernel)

[🇺🇸 English](#en--english) | [🇷🇺 Русский](#ru--русский)

<div align="center">
  <img src="https://img.shields.io/badge/Device-Redmi_Note_11-FF6900?style=for-the-badge&logo=xiaomi&logoColor=white" />
  <img src="https://img.shields.io/badge/Kernel-4.19.157_Non--GKI-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img src="https://img.shields.io/badge/Android-12_to_15-3DDC84?style=for-the-badge&logo=android&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-Active_Development-8C1515?style=for-the-badge" />
</div>

<br/>

## EN / English

**A highly customized, stealth-focused Non-GKI kernel (4.19.157) for Redmi Note 11 / Redmi Note 11 NFC (`spes`/`spesn`).** 

Built for performance, penetration testing, and ultimate root hiding. Successfully tested on Android 12, but universally supports Android 12-15 with no artificial restrictions.

### Branches & Versions
I maintain different branches of this kernel to suit different needs. Choose your version:

| Feature | [main (Ultimate)](../../tree/main) | [clean (Basic)](../../tree/clean) | *3rd Branch (Planned)* |
| :--- | :---: | :---: | :---: |
| **KernelSU-Next** | ✅ Yes | ❌ No | ⏳ TBD |
| **SusFS v2.1.0** (Hide Root) | ✅ Yes | ❌ No | ⏳ TBD |
| **AKernel Driver** (Ring 0) | ✅ Yes | ❌ No | ⏳ TBD |
| **NetHunter / SDR Ready** | ✅ Yes | ❌ No | ⏳ TBD |
| **TCP BBR** (Fast Network) | ✅ Yes | ✅ Yes | ⏳ TBD |
| **TTL Bypass** (Tethering) | ✅ Yes | ✅ Yes | ⏳ TBD |
| **Deep Debloat & Opts** | ✅ Yes | ✅ Yes | ⏳ TBD |

---

### 1. Core Feature: AKernel Subsystem
* **Custom Ring 0 Bridge:** Integrated custom `drivers/akernel` to allow direct interaction with the kernel (Ring 0) from user space (Ring 3) bypassing standard Android APIs. *(Currently in early development).*
* **Isolated Development:** Connected as an independent Git submodule.
* **Stealth Mode:** Protected by the `CONFIG_AKERNEL_HIDE=y` flag to evade anti-cheat memory scanners.

### 2. Ultimate Stealth & Anti-Cheat Bypass
Deeply modified to bypass the strictest checks (Play Integrity, Vanguard, Banking apps).
* **KernelSU-Next:** Vendored with the latest KernelSU-Next (v3.2.0-legacy). 
* **SusFS v2.1.0 (Superuser Spoofing):** Deep VFS integration for Path, Mount, Memory, and FD Spoofing.
* **Kallsyms Cleaner:** Completely purges KernelSU and SusFS functions (`ksu_`, `susfs_`) from `/proc/kallsyms`.
* **SELinux AVC Spoofing:** Intercepts SELinux logs and replaces root SIDs with `priv_app` to leave no traces in `dmesg`/`logcat`.

### 3. Network & NetHunter Ready
* **TCP BBR:** Google's BBR congestion control algorithm enabled by default (`CONFIG_TCP_CONG_BBR=y`).
* **TTL Spoofing:** Fixed TTL support (`CONFIG_NETFILTER_XT_TARGET_HL=y`) to bypass carrier tethering restrictions.
* **Pentesting Ready:** Drivers included for external Wi-Fi adapters (`RTL8821CU`, `RTL8187`, `RTL8XXXU`) and SDR.

### 4. Performance & Containers
* **Debloat:** Stripped heavy debugging modules (`CONFIG_CORESIGHT`, `SLUB_DEBUG`, `SCHEDSTATS`, `DEBUG_INFO`).
* **Docker/LXC Support:** Namespaces enabled (`USER_NS`, `IPC_NS`, `PID_NS`).
* **DTB Cleanup:** Removed dead audio routes from `bengal-audio-overlay.dtsi` to speed up hardware initialization.

### 5. Automated Build System
* Includes a custom `build.sh` script (auto-downloads Clang, compiles, and patches **AnyKernel3**).

<br/>

> *Love and kisses to everyone! I hope you enjoy my projects.* 🤍

---

## RU / Русский

**Кастомное Non-GKI ядро (4.19.157) с максимальным упором на скрытность для Redmi Note 11 / Redmi Note 11 NFC (`spes`/`spesn`).**

Создано для производительности, пентестинга и абсолютной маскировки Root-прав. Поддерживает Android 12-15.

### Ветки и версии
Я поддерживаю разные ветки этого ядра под разные задачи. Выберите свою версию:

| Функционал | [main (Ultimate)](../../tree/main) | [clean (Basic)](../../tree/clean) | *3-я ветка (В планах)* |
| :--- | :---: | :---: | :---: |
| **KernelSU-Next** | ✅ Есть | ❌ Нет | ⏳ Ждем |
| **SusFS v2.1.0** (Скрытие рута) | ✅ Есть | ❌ Нет | ⏳ Ждем |
| **AKernel Driver** (Ring 0) | ✅ Есть | ❌ Нет | ⏳ Ждем |
| **NetHunter / SDR Ready** | ✅ Есть | ❌ Нет | ⏳ Ждем |
| **TCP BBR** (Быстрая сеть) | ✅ Есть | ✅ Есть | ⏳ Ждем |
| **Обход TTL** (Раздача инета) | ✅ Есть | ✅ Есть | ⏳ Ждем |
| **Debloat и Оптимизация** | ✅ Есть | ✅ Есть | ⏳ Ждем |

---

### 1. Главная особенность: Подсистема AKernel
* **Собственный драйвер ядра:** Интегрирован кастомный драйвер `drivers/akernel` для прямого взаимодействия с Ring 0. *(Ранняя стадия разработки).*
* **Изолированная разработка:** Подключен как независимый Git-сабмодуль.
* **Режим невидимости:** Защищен флагом `CONFIG_AKERNEL_HIDE=y` для защиты от античитов.

### 2. Root и Максимальная Скрытность
Ядро глубоко модифицировано для обхода проверок (Play Integrity, Vanguard, банки).
* **KernelSU-Next:** Вшита актуальная версия (v3.2.0-legacy).
* **SusFS v2.1.0:** Глубокая интеграция VFS (скрытие путей, монтирования, памяти и FD).
* **Kallsyms Hide:** Полное удаление функций KernelSU и SusFS из `/proc/kallsyms`.
* **SELinux AVC Spoofing:** Перехват логов SELinux для подмены SID на `priv_app`.

### 3. Сеть и Pentesting (NetHunter Ready)
* **TCP BBR:** Включен алгоритм контроля перегрузки сети Google BBR.
* **Обход TTL:** Поддержка фиксации TTL для бесплатной раздачи интернета.
* **External Wi-Fi & SDR:** Добавлены драйверы внешних адаптеров (`RTL8821CU`, `RTL8187`, `RTL8XXXU`) и поддержка SDR.

### 4. Производительность и Контейнеры
* **Debloat:** Вырезаны отладочные модули (`CONFIG_CORESIGHT`, `SLUB_DEBUG`, `SCHEDSTATS`, `DEBUG_INFO`).
* **Поддержка Docker:** Включены пространства имен (`USER_NS`, `IPC_NS`, `PID_NS`).
* **Очистка DTB:** Удалены мертвые маршруты аудио для ускорения инициализации.

### 5. Автоматизация сборки
* Кастомный скрипт `build.sh` (автоскачивание Clang, компиляция и патчинг **AnyKernel3** на лету).

<br/>

> *Всех люблю, всех целую! Надеюсь, вам понравятся мои проекты.* 🤍
