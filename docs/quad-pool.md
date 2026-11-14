# Quad Pool (4 пула)

Режим `Quad Pool` (`poolMode = 2`) добавлен рядом с `Failover` (0) и `Dual Pool` (1).
Четыре пула подключены одновременно, задания распределяются по весам пулов
(smooth weighted round-robin). Вес `0` = пул подключён, но работу не получает;
если все веса нулевые, вся работа уходит первому живому пулу.

Статистика, сложность, ping и проверка coinbase ведутся отдельно для каждого из
4 пулов. Новая вкладкаSettings и дашборд показывают 4 пула и их доли хешрейта.

## Включение

1. Settings → **Pool Mode → Quad Pool**.
2. Заполнить вкладки пулов 1–4 и вес каждого (по умолчанию `25/25/25/25`).
3. Сохранить и **перезагрузить** — менеджер пулов создаётся при старте.

## Прошивка через штатный веб-интерфейс

Блок ручной загрузки прошивки скрыт: он появляется только при включённом
«Danger Zone» (`localStorage['support-level'] >= 1`).

1. Открыть `http://<IP>/#/pages/settings`.
2. В заголовке карточки **Mining Settings** справа есть еле заметный значок ⚠
   (подсказка `Danger Zone`). Один клик включает `Advanced` на 24 часа.
   Альтернатива — в консоли браузера:
   ```js
   localStorage.setItem('support-level', '1');
   localStorage.setItem('support-level-expiry', String(Date.now() + 86400000));
   location.reload();
   ```
3. Появится карточка **Legacy**:
   - **Manual Firmware Update** → `esp-miner-NerdQAxe+.bin` → `Flash`,
   - после перезагрузки **Manual WWW Update** → `www.bin` → `Flash`.

Имена файлов проверяются панелью буквально; порядок «сначала firmware, потом www»
обязателен, иначе новая панель будет обращаться к старому API.

Блок `Release & Update / Install from GitHub` обращается к апстриму
`shufps/ESP-Miner-NerdQAxePlus`, поэтому релизы этого форка в нём не видны —
используйте ручную загрузку или `POST /api/system/OTA` и `/api/system/OTAWWW`.

Готовые бинарники и полная инструкция: https://github.com/skleptik/ESP-Miner-NerdQAxePlus/releases

## Сборка

```bash
BOARD=NERDQAXEPLUS idf.py set-target esp32s3
BOARD=NERDQAXEPLUS idf.py build          # внутри esp-idf-builder:5.3.6
cd main/http_server/axe-os && npm ci && npm run build
```

Для других плат замените `BOARD` (`NERDQAXEPLUS2`, `NERDQX`, ...).
`www.bin` одинаков для всех плат.
