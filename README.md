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

### 1. Core Feature: AKernel Subsystem
* **Custom Ring 0 Bridge:** Integrated custom `drivers/akernel` to allow direct interaction with the kernel (Ring 0) from user space (Ring 3) bypassing standard Android APIs. **(Check [AKernel](https://github.com/angeloxhek/AKernel)).**
* **Isolated Development:** Connected as an independent Git submodule, allowing updates without touching the main kernel tree.
* **Stealth Mode:** Protected by the `CONFIG_AKERNEL_HIDE=y` flag to evade anti-cheat memory scanners.

### 2. Ultimate Stealth & Anti-Cheat Bypass
Deeply modified to bypass the strictest checks (Play Integrity, Vanguard, Banking apps).
* **KernelSU-Next:** Vendored with the latest KernelSU-Next (v3.2.0-legacy). Auto-detects versions without needing the `.git` folder.
* **SusFS v2.1.0 (Superuser Spoofing):** Deep VFS (Virtual File System) integration:
  * **Path Spoofing:** Hides paths and mounts from user apps (hooks in `fs/namespace.c`, `fs/namei.c`, `fs/readdir.c`).
  * **Memory & FD Stealth:** Wipes root traces from `/proc/pid/maps`, `smaps`, and `fdinfo`.
  * **Kallsyms Cleaner:** Completely purges KernelSU and SusFS functions (`ksu_`, `susfs_`) from `/proc/kallsyms` to blind Ring 0 scanners.
  * **SELinux AVC Spoofing:** Intercepts SELinux logs. If a root policy violation occurs, the kernel silently replaces the SID with `priv_app`, leaving no traces of KSU in `dmesg`/`logcat`.

### 3. Network & NetHunter Ready
* **TCP BBR:** Google's BBR congestion control algorithm enabled by default (`CONFIG_TCP_CONG_BBR=y`) for minimum ping and maximum throughput.
* **TTL Spoofing:** Fixed TTL support (`CONFIG_NETFILTER_XT_TARGET_HL=y`) to bypass carrier tethering restrictions.
* **Pentesting Ready:** 
  * Drivers included for external Wi-Fi adapters (`RTL8821CU`, `RTL8187`, `RTL8XXXU`) — perfect for monitor mode and packet injection.
  * Support for Software Defined Radio (SDR) and `USB_RTL2832`.
  * Support for USB network adapters (`USB_USBNET`, `CDCETHER`).

### 4. Performance & Containers
* **Debloat:** Stripped heavy debugging modules to reduce kernel size and compile time (`CONFIG_CORESIGHT`, `SLUB_DEBUG`, `SCHEDSTATS`, `DEBUG_INFO`).
* **Docker/LXC Support:** Namespaces enabled (`USER_NS`, `IPC_NS`, `PID_NS`). Fully ready for Linux Deploy and Containers.
* **DTB Cleanup:** Removed dead audio routes from `bengal-audio-overlay.dtsi` to speed up hardware initialization specifically for `spes`.

### 5. Automated Build System
* Includes a custom `build.sh` script.
* Automatically downloads the Clang toolchain, compiles the kernel, and patches the **AnyKernel3** configuration on the fly using `sed`.
* Outputs a ready-to-flash `AKernel-spes-XXXX.zip` archive.

<br/>

> *Love and kisses to everyone! I hope you enjoy my projects.* 🤍

---

## RU / Русский

**Кастомное Non-GKI ядро (4.19.157) с максимальным упором на скрытность для Redmi Note 11 / Redmi Note 11 NFC (`spes`/`spesn`).**

Создано для производительности, пентестинга и абсолютной маскировки Root-прав. Оттестировано на Android 12, но ограничения сняты — ядро отлично поддерживает Android 12-15.

### 1. Главная особенность: Подсистема AKernel
* **Собственный драйвер ядра:** Интегрирован кастомный драйвер `drivers/akernel` для прямого взаимодействия с Ring 0 из Ring 3 в обход стандартного API. **(Смотри [AKernel](https://github.com/angeloxhek/AKernel)).**
* **Изолированная разработка:** Подключен как независимый Git-сабмодуль, что позволяет обновлять его отдельно от дерева ядра.
* **Режим невидимости:** Защищен флагом `CONFIG_AKERNEL_HIDE=y` для защиты от обнаружения античитами.

### 2. Root и Максимальная Скрытность (Anti-Cheat Bypass)
Ядро глубоко модифицировано для обхода самых строгих проверок (Play Integrity, Vanguard, банки).
* **KernelSU-Next:** Вшита (vendored) актуальная версия KernelSU-Next (v3.2.0-legacy). Собирается без необходимости хранить папку `.git`.
* **SusFS v2.1.0 (Superuser Spoofing Filesystem):** Глубокая интеграция на уровне VFS ядра:
  * **Path & Mount Spoofing:** Скрытие путей и точек монтирования от приложений (хуки в `fs/namespace.c`, `fs/namei.c`, `fs/readdir.c`).
  * **Memory & FD Stealth:** Очистка следов рута из памяти процессов и файловых дескрипторов (`/proc/pid/maps`, `smaps`, `fdinfo`).
  * **Kallsyms Hide:** Полное удаление функций KernelSU и SusFS из `/proc/kallsyms`, чтобы сканеры не могли найти их в Ring 0.
  * **SELinux AVC Spoofing:** Перехват логов SELinux (`dmesg`/`logcat`). При нарушениях политик рутом, ядро подменяет идентификатор процесса (SID) на `priv_app`, не оставляя следов работы KSU.

### 3. Сеть и Pentesting (NetHunter Ready)
* **TCP BBR:** Включен алгоритм контроля перегрузки сети Google BBR (`CONFIG_TCP_CONG_BBR=y`) для максимальной скорости и снижения пинга.
* **Обход ограничений (TTL Patch):** Поддержка фиксации TTL (`CONFIG_NETFILTER_XT_TARGET_HL=y`) для бесплатной раздачи интернета.
* **External Wi-Fi & SDR:** 
  * Добавлены драйверы внешних Wi-Fi адаптеров (`RTL8821CU`, `RTL8187`, `RTL8XXXU`) — идеально для режима монитора и инъекции пакетов.
  * Поддержка Software Defined Radio (SDR) и `USB_RTL2832`.
  * Поддержка сетевых USB-адаптеров.

### 4. Производительность и Контейнеры
* **Debloat (Удаление мусора):** Вырезаны тяжелые отладочные модули для снижения веса и ускорения ядра (`CONFIG_CORESIGHT`, `SLUB_DEBUG`, `SCHEDSTATS`, `DEBUG_INFO`).
* **Поддержка Docker:** Включены пространства имен (`USER_NS`, `IPC_NS`, `PID_NS`). Ядро готово для запуска Docker, LXC и Linux Deploy.
* **Очистка DTB:** Удалены мертвые маршруты аудио из `bengal-audio-overlay.dtsi` для ускорения инициализации железа (специфично для базы `spes`).

### 5. Автоматизация сборки
* Написан кастомный скрипт `build.sh`.
* Скрипт автоматически качает нужный тулчейн (Clang), компилирует ядро и патчит конфигурацию **AnyKernel3** "на лету" с помощью `sed`.
* На выходе получается готовый для прошивки через TWRP/KSU архив `AKernel-spes-XXXX.zip`.

<br/>

> *Всех люблю, всех целую! Надеюсь, вам понравятся мои проекты.* 🤍
