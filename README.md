<div align="center">
  <a href="README.md">English</a>
  ·
  <a href="README_ES.md">Español</a>
  ·
  <a href="README_CN.md">中文</a>
</div>

<div align="center">
  <img src="icon.png" alt="Playerbots" width="256" />
</div>

<h1 align="center">Playerbots Reload Module</h1>

<p align="center">
  An <a href="https://www.azerothcore.org/">AzerothCore</a> module that adds player-like bots to a WotLK 3.3.5a server.
  <br />
  <strong>This repository is a fork/repack used to ship experimental features under test.</strong>
</p>

<p align="center">
  Repository: <a href="https://github.com/kambire/playerbots-reload-module">kambire/playerbots-reload-module</a>
</p>

---

## Overview
This module provides player-like bots that can:
- log in as alternate characters and participate in parties
- roam the world as random bots and simulate an MMO population
- run most dungeons/raids and battlegrounds
- be configured through a dedicated configuration file

## About this fork (experimental)
This repository exists to:
- apply maintenance fixes (build compatibility, warning cleanup)
- introduce new/experimental features before upstreaming them
- keep documentation more explicit for installation and troubleshooting

If you want the “upstream” project, see:
- Upstream module: https://github.com/mod-playerbots/mod-playerbots

## Compatibility / Requirements
- Game version: WotLK 3.3.5a
- Core: AzerothCore WotLK
- **Required core branch:** https://github.com/mod-playerbots/azerothcore-wotlk/tree/Playerbot

> Note: This module will not build/function correctly on standard AzerothCore without the `Playerbot` branch.

## Installation

### Option 1 — Fresh install (recommended)
```bash
git clone https://github.com/mod-playerbots/azerothcore-wotlk.git --branch=Playerbot
cd azerothcore-wotlk/modules
git clone https://github.com/kambire/playerbots-reload-module.git --branch=main mod-playerbots
```

Re-run CMake and rebuild your core (see AzerothCore installation docs).

### Option 2 — Add to an existing Playerbot-branch core
```bash
cd /path/to/azerothcore-wotlk/modules
git clone https://github.com/kambire/playerbots-reload-module.git --branch=main mod-playerbots
```

### Updating
```bash
cd /path/to/azerothcore-wotlk/modules/mod-playerbots
git checkout main
git pull
```

If code changed, rebuild the core.

### Windows + WSL note
If your build logs show paths like `/home/user/...`, you are building in Linux/WSL.
Edits made on a Windows path (e.g. `D:\...`) will not affect the WSL build unless you are compiling the same checkout.

## Configuration
This module ships with a configuration template:
- `conf/playerbots.conf.dist`

Typical setup:
1) Copy `conf/playerbots.conf.dist` into your server config directory
2) Rename it to `playerbots.conf`
3) Adjust settings as needed

## Database / SQL
SQL content is provided under:
- `data/sql/`

> TODO: Document exact DB import/upgrade flow for this fork (which databases, which order, and whether db_assembler is used in your deployment).

## Usage
- Bots are controlled primarily through in-game chat commands.
- Community UI AddOns are available to manage bots more comfortably.

Documentation pointers:
- Wiki: https://github.com/mod-playerbots/mod-playerbots/wiki
- AddOns & submodules: https://github.com/mod-playerbots/mod-playerbots/wiki/Playerbot-Addons-and-Sub%E2%80%90Modules

## Troubleshooting
- If the module compiles but bots don’t behave as expected:
  - verify the config was loaded
  - verify required SQL was applied
  - verify you are on the required `Playerbot` branch
- If your edits “don’t change anything”:
  - confirm you’re compiling the same checkout (Windows vs WSL path mismatch)

## Contributing
This fork is under active development and experimental work.
If you find issues, please open an issue in the upstream project when it reproduces there, or open an issue here if it is specific to this fork.

For C++ changes, please follow AzerothCore C++ standards:
- https://www.azerothcore.org/wiki/cpp-code-standards

Community:
- Discord: https://discord.gg/NQm5QShwf9

## License
This project is released under the GNU AGPL v3 (see `LICENSE`).

## Credits / Acknowledgements
This project is based on the original playerbots work and the ongoing community effort:
- Upstream module: https://github.com/mod-playerbots/mod-playerbots
- Origins and prior repositories referenced by upstream:
  - https://github.com/ZhengPeiRu21/mod-playerbots
  - https://github.com/celguar/mangosbot-bots
- Early base reference: https://github.com/ike3/mangosbot

Special thanks to the upstream maintainers and the many contributors who built the project:

<a href="https://github.com/mod-playerbots/mod-playerbots/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=mod-playerbots/mod-playerbots" alt="Contributors" />
</a>
