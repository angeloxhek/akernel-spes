# 📱 akernel-spes (Stealth Root Edition)

[🇺🇸 English](#en--english) | [🇷🇺 Русский](#ru--русский)

<div align="center">
  <img src="https://img.shields.io/badge/Device-Redmi_Note_11-FF6900?style=for-the-badge&logo=xiaomi&logoColor=white" />
  <img src="https://img.shields.io/badge/Kernel-4.19.157_KSU%2BSusFS-8C1515?style=for-the-badge&logo=linux&logoColor=white" />
  <img src="https://img.shields.io/badge/Android-12_to_15-3DDC84?style=for-the-badge&logo=android&logoColor=white" />
  <img src="https://img.shields.io/badge/Focus-Root_&_Stealth-black?style=for-the-badge" />
</div>

<br/>

## EN / English

**A perfectly balanced Non-GKI kernel for Redmi Note 11 / Redmi Note 11 NFC (`spes`/`spesn`).** 

This branch is the "Golden Mean". It is designed for daily users who need **Root access and ultimate Anti-Cheat bypass**, but do not need heavy penetration testing tools (like NetHunter or custom Ring 0 drivers) present in the `main` branch.

### 1. Ultimate Stealth (Anti-Cheat Bypass)
Deeply modified to bypass the strictest checks (Play Integrity, Vanguard, Banking apps).
* **KernelSU-Next:** Vendored with the latest KernelSU-Next (v3.2.0-legacy). 
* **SusFS v2.1.0 (Superuser Spoofing):** Deep VFS integration to hide your rooted state:
  * **Path & Mount Spoofing:** Hides paths and mounts from user apps.
  * **Memory & FD Stealth:** Wipes root traces from `/proc/pid/maps`, `smaps`, and `fdinfo`.
  * **Kallsyms Cleaner:** Completely purges KernelSU and SusFS functions (`ksu_`, `susfs_`) from `/proc/kallsyms`.
  * **SELinux AVC Spoofing:** Intercepts SELinux logs and replaces root SIDs with `priv_app` to leave no traces in `dmesg`/`logcat`.

### 2. Pentest-Free Architecture
* **No Extra Overhead:** The custom `AKernel` driver and NetHunter/SDR drivers are completely removed. The kernel focuses purely on providing a stable, undetectable rooted environment for your daily driver.
* **Clean Identification:** Shows up with a proper custom localversion in Android Settings.

### 3. Advanced Networking
* **TCP BBR Enabled:** Google's BBR congestion control is set as default (`CONFIG_TCP_CONG_BBR=y`). Your internet connection will fly.
* **TTL Spoofing Fix:** Carrier tethering restrictions bypassed natively via `CONFIG_IP_NF_TARGET_HL=y`.

### 4. Extreme Debloat & Performance
* **Debugging Purged:** The massive `CONFIG_CORESIGHT` block has been completely ripped out.
* **No Overhead:** `CONFIG_SCHEDSTATS` and `CONFIG_DEBUG_INFO` are disabled. The kernel is extremely lightweight, keeping the phone fast and cold.
* **DTB Cleanup:** Removed dead audio routes from `bengal-audio-overlay.dtsi` for faster hardware initialization and boot times.

### 🛠 5. Automated Build System
* The `build.sh` script automatically downloads the Clang toolchain, compiles the kernel, and patches the **AnyKernel3** configuration on the fly. 

<br/>

> *Love and kisses to everyone! I hope you enjoy my projects.* 🤍

---

## RU / Русский

**Идеально сбалансированное Non-GKI ядро для Redmi Note 11 / Redmi Note 11 NFC (`spes`/`spesn`).**

Эта ветка — «Золотая середина». Она создана для пользователей, которым нужен **полноценный Root-доступ и 100% обход античитов/банков**, но не нужны тяжелые инструменты для пентестинга (NetHunter или кастомные драйверы), которые есть в ветке `main`.

### 1. Максимальная Скрытность (Anti-Cheat Bypass)
Ядро модифицировано для обхода самых строгих проверок (Play Integrity, Vanguard, банковские приложения).
* **KernelSU-Next:** Вшита актуальная версия KernelSU-Next (v3.2.0-legacy).
* **SusFS v2.1.0 (Superuser Spoofing Filesystem):** Глубокая интеграция на уровне VFS ядра:
  * **Path & Mount Spoofing:** Скрытие путей и точек монтирования от приложений.
  * **Memory & FD Stealth:** Очистка следов рута из памяти процессов (`/proc/pid/maps`, `smaps`, `fdinfo`).
  * **Kallsyms Hide:** Полное удаление функций KernelSU и SusFS из `/proc/kallsyms`, чтобы сканеры не могли найти их в Ring 0.
  * **SELinux AVC Spoofing:** Перехват логов SELinux (`dmesg`/`logcat`). Ядро подменяет идентификатор рут-процесса на `priv_app`, не оставляя следов.

### 2. Архитектура без хакерского "оверхеда"
* **Только нужное:** Кастомный драйвер `AKernel` и драйверы для NetHunter/SDR полностью удалены. Ядро сфокусировано исключительно на стабильной и скрытной работе системы с рут-правами на каждый день.
* **Правильное имя:** В настройках Android отображается аккуратное имя кастомной версии ядра.

### 3. Прокачанная сеть
* **TCP BBR:** Включен алгоритм контроля перегрузки сети BBR (`CONFIG_TCP_CONG_BBR=y`). Интернет будет летать.
* **Обход TTL:** Добавлена нативная поддержка фиксации TTL (`CONFIG_IP_NF_TARGET_HL=y`). Раздача интернета будет работать.

### 4. Глубокий Debloat и Производительность
* **Никакого мусора:** Огромный блок отладки `CONFIG_CORESIGHT` полностью вырезан.
* **Никакой просадки:** `CONFIG_SCHEDSTATS` и `CONFIG_DEBUG_INFO` отключены. Ядро легкое, быстрое и не греет телефон.
* **Очистка DTB:** Из `bengal-audio-overlay.dtsi` вырезаны мертвые аудио-маршруты, что ускоряет инициализацию железа при загрузке.

### 5. Автоматизация сборки
* Кастомный скрипт `build.sh` автоматически качает нужный тулчейн (Clang), компилирует ядро и патчит конфигурацию **AnyKernel3** "на лету".

<br/>

> *Всех люблю, всех целую! Надеюсь, вам понравятся мои проекты.* 🤍
