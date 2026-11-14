# YYSLUPING NerdYYSP++ 8 TH/s (большой экран 480×320)

Этот форк (`skleptik/nerdqaxeplus2-ethernet`) = `AguiMr/nerdqaxeplus2-ethernet`
(открытая поддержка экрана 480×320 + Ethernet) + портированный quad-pool режим
из `skleptik/ESP-Miner-NerdQAxePlus`.

## Аппаратные отличия от стокового NerdQAxe++

| | Сток NerdQAxe++ | YYSLUPING 8 TH/s |
|---|---|---|
| Экран | 320×170 (1.9") | **480×320 (3.5")** |
| Flash | 16 МБ | **32 МБ** |
| Питание | 100 Вт / 8 А | **~150 Вт / 12–13 А / 300 Вт макс.** |
| Частота | до 800/1000 МГц | **1000 МГц @ 1250 мВ** |
| ASIC | 4 × BM1370 | 4 × BM1370 |
| Ток ядра (1.25 В) | ≤ 95 А | **~104 А** |

Вендорская прошивка закрытая: https://github.com/yysluping/vastbtc
(в репозитории только `www.bin`, исходников нет).
Таблица разделов вендора: app 5 МБ @ `0x10000`, `www` 3 МБ @ `0x1000000`,
`otadata` @ `0xf10000`. NVS — `0x9000`, 24 КБ (совпадает с нашим).

## Сборка

```bash
export BOARD=NERDQAXEPLUS2
export BIGSCREEN=1          # 480×320
export YYSP_HIGH_POWER=1    # профиль 8 TH/s
./docker/idf.sh set-target esp32s3
./docker/idf.sh build
```

`YYSP_HIGH_POWER` включает в `main/boards/nerdqaxeplus2.cpp`:
- `m_maxPin = 300`, `m_maxCurrentA = 25` — шкалы тока/мощности в UI не обрезаются;
- `m_absMaxAsicFrequency = 1000` и частоты до 1000 МГц **в конструкторе**
  (иначе `Board::loadSettings()` успевает зажать частоту до 800 МГц);
- напряжения до 1300 мВ;
- **`m_ifault = 180 А`** — критично. Апстрим ставит
  `PMBUS_IOUT_OC_FAULT_LIMIT = 95 А` (3 фазы × 30 + 5), а это железо на
  1000 МГц/1.25 В потребляет ~104 А по ядру. Без правки `getFault()` видит
  `IOUT_OCF`, `power_management_task` вызывает `setVoltage(0.0)` и на экране
  появляется **«CURRENT PROTECTION»** (майнер стоит с нулевым хешрейтом).

Дополнительно в `home/tiles/utils.ts` шкала тока сама расширяется, если
измеренный ток превышает `maxCurrentA` (страховка для любого железа).

## Прошивка

Первый раз с вендорской прошивки — **только USB** (таблица разделов меняется):

```bash
python3 -m esptool --chip esp32s3 --port /dev/cu.usbmodemXXXX --baud 460800 \
  write-flash --flash-mode dio --flash-size 32MB --flash-freq 80m \
  0x0 esp-miner-factory-yyslupingB++-quad.bin
```

Чтобы сохранить Wi‑Fi/частоту/напряжение, factory-образ собирается из
`merge-bin` с подстановкой байт `0x9000–0x10000` (NVS + phy_init) из дампа
старой прошивки. Бэкап перед прошивкой обязателен:

```bash
python3 -m esptool --chip esp32s3 --port /dev/cu.usbmodemXXXX read-flash 0 0x2000000 backup-32MB.bin
```

Дальнейшие обновления приложения — через `POST /api/system/OTA` или заливку
`0x10000` (NVS не трогается). `www.bin` — 2 МБ @ `0x4a0000`.

## Проверено на реальном приборе

`192.168.10.20`: 8.18 TH/s, 153 Вт, 13 А, 1.25 В, 1000 МГц, 4 пула
(`activePoolMode=2`), воркеры `YY_1…YY_4`, шары принимаются всеми пулами.
Экран 480×320, «CURRENT PROTECTION» отсутствует.
