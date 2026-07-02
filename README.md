# 📱 akernel-spes (Clean Edition)

[🇺🇸 English](#en--english) | [🇷🇺 Русский](#ru--русский)

<div align="center">
  <img src="https://img.shields.io/badge/Device-Redmi_Note_11-FF6900?style=for-the-badge&logo=xiaomi&logoColor=white" />
  <img src="https://img.shields.io/badge/Kernel-4.19.157_Clean-3776AB?style=for-the-badge&logo=linux&logoColor=white" />
  <img src="https://img.shields.io/badge/Android-12_to_15-3DDC84?style=for-the-badge&logo=android&logoColor=white" />
  <img src="https://img.shields.io/badge/Focus-Speed_&_Stability-4EAA25?style=for-the-badge" />
</div>

<br/>

## EN / English

**A crystal-clean, highly optimized Non-GKI kernel for Redmi Note 11 / Redmi Note 11 NFC (`spes`/`spesn`).** 

Unlike the `main` branch, this version contains **NO hacking tools, NO KernelSU, NO SusFS, and NO custom ring 0 bridges**. It is built purely for users who want a lightweight, fast, and cool device with maximum stock-like security and network optimizations.

### 1. Crystal Clean Architecture
* **Zero Hooks:** The VFS (Virtual File System) remains untouched. `CONFIG_KSU`, `CONFIG_KSU_SUSFS`, and `CONFIG_AKERNEL` are completely removed.
* **Stock Security:** Passes all integrity checks naturally, without spoofing, because it acts just like a stock kernel.
* **Clean Identification:** Shows up as `-AKernel-clean-1.0` in Android Settings.

### 2. Advanced Networking
* **TCP BBR Enabled:** Google's BBR congestion control is set as default (`CONFIG_TCP_CONG_BBR=y`). Your internet connection will fly.
* **TTL Spoofing Fix:** Carrier tethering restrictions bypassed natively via `CONFIG_IP_NF_TARGET_HL=y`.

### 3. Extreme Debloat & Performance
* **Debugging Purged:** The massive `CONFIG_CORESIGHT` block has been completely ripped out.
* **No Overhead:** `CONFIG_SCHEDSTATS` and `CONFIG_DEBUG_INFO` are disabled. The kernel is extremely lightweight, keeping the phone fast and cold.
* **DTB Cleanup:** Removed dead audio routes from `bengal-audio-overlay.dtsi` for faster hardware initialization and boot times.

### 4. User-Friendly Installer
* The `build.sh` script automatically patches **AnyKernel3** during compilation. 
* Flashing in TWRP/OrangeFox provides a clean, reassuring prompt: `A basic kernel`.

<br/>

> *Love and kisses to everyone! I hope you enjoy my projects.* 🤍

---

## RU / Русский

**Кристально чистое, максимально оптимизированное Non-GKI ядро для Redmi Note 11 / Redmi Note 11 NFC (`spes`/`spesn`).**

В отличие от ветки `main`, эта версия **НЕ содержит хакерского кода, KernelSU, SusFS и кастомных драйверов**. Она создана исключительно для пользователей, которым нужен легкий, холодный и быстрый телефон со стоковой безопасностью и улучшенной сетью.

### 1. Кристально чистая архитектура
* **Ноль хуков:** Файловая система (VFS) абсолютно чиста. В конфиге вырезаны `CONFIG_KSU`, `CONFIG_KSU_SUSFS` и `CONFIG_AKERNEL`.
* **Нативная безопасность:** Проходит проверки целостности (Play Integrity) естественным путем, без спуфинга, так как не имеет встроенного рута.
* **Правильное имя:** В настройках Android отображается аккуратное `-AKernel-clean-1.0`.

### 2. Прокачанная сеть
* **TCP BBR:** Включен алгоритм контроля перегрузки сети BBR (`CONFIG_TCP_CONG_BBR=y`). Интернет будет летать.
* **Обход TTL:** Добавлена нативная поддержка фиксации TTL (`CONFIG_IP_NF_TARGET_HL=y`). Раздача интернета будет работать даже при блокировках оператора.

### 3. Глубокий Debloat и Производительность
* **Никакого мусора:** Огромный блок отладки `CONFIG_CORESIGHT` полностью вырезан.
* **Никакой просадки:** `CONFIG_SCHEDSTATS` и `CONFIG_DEBUG_INFO` отключены. Ядро получилось очень легким, быстрым и не греет телефон.
* **Очистка DTB:** Из `bengal-audio-overlay.dtsi` вырезаны мертвые аудио-маршруты, что ускоряет инициализацию железа при загрузке.

### 4. Забота о пользователе (Установщик)
* Скрипт `build.sh` автоматически патчит **AnyKernel3** при компиляции.
* Во время прошивки через кастомное рекавери установщик честно пишет: `A basic kernel` — топ-уровень заботы о пользователе.

<br/>

> *Всех люблю, всех целую! Надеюсь, вам понравятся мои проекты.* 🤍
