<p align="center">
  <a href="README.md">English</a>
    |
  <a href="README_CN.md">中文</a>
    |
  <a href="README_ES.md">Español</a>
</p>


<div align="center">
  <img src="icon.png" alt="Playerbots Icon" width="700px">
</div>

# Playerbots Module
`mod-playerbots` is an [AzerothCore](https://www.azerothcore.org/) module that adds player-like bots to a server. The project is based off [IKE3's Playerbots](https://github.com/ike3/mangosbot).

> **Work in progress / experimental fork (this repository)**
>
> This repository is a repack/fork intended to be published as **`playerbots-reload-module`**.
> It keeps upstream content where possible, but this version is specifically used to **add and validate new features that are still in testing**.
> Expect changes, refactors, and occasional behavior differences compared to upstream.
>
> TODO: Document which upstream commit/branch this fork is based on.

## Contents
- [Features](#features)
- [Installation](#installation)
- [Configuration](#configuration)
- [Database / SQL](#database--sql)
- [Documentation](#documentation)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [Acknowledgements](#acknowledgements)

## Features
Features include:

- The ability to log in alt characters as bots, allowing players to interact with their other characters, form parties, level up, and more
- Random bots that wander through the world, complete quests, and otherwise behave like players, simulating the MMO experience
- Bots capable of running most raids and battlegrounds
- Highly configurable settings to define how bots behave
- Excellent performance, even when running thousands of bots

We also have a **[Discord server](https://discord.gg/NQm5QShwf9)** where you can discuss the project, ask questions, and get involved in the community!

## Installation

Supported platforms are Ubuntu, Windows, and macOS. Other Linux distributions may work, but may not receive support. 

**All `mod-playerbots` installations require a custom branch of AzerothCore: [mod-playerbots/azerothcore-wotlk/tree/Playerbot](https://github.com/mod-playerbots/azerothcore-wotlk/tree/Playerbot).** This branch allows the `mod-playerbots` module to build and function. Updates from the upstream are implemented regularly to this branch. Instructions for installing this required branch and this module are provided below.

### Quick start (recommended)
Clone the required AzerothCore branch and then clone this module into `modules/mod-playerbots`:

```bash
git clone https://github.com/mod-playerbots/azerothcore-wotlk.git --branch=Playerbot
cd azerothcore-wotlk/modules
git clone https://github.com/kambire/playerbots-reload-module.git --branch=main mod-playerbots
```

Then rebuild AzerothCore (see "Build / Rebuild" below) and configure the module (see "Configuration").

### Install into an existing AzerothCore checkout
If you already have AzerothCore cloned (and already switched to the required `Playerbot` branch), you only need to add the module:

```bash
cd /path/to/azerothcore-wotlk/modules
git clone https://github.com/kambire/playerbots-reload-module.git --branch=main mod-playerbots
```

Notes:
- The folder name under `modules/` must be `mod-playerbots`.
- If you previously had another `mod-playerbots` folder, remove/rename it first.

### Build / Rebuild
After cloning the module, you must re-run CMake and rebuild.

General flow (platform-agnostic):
1) Re-run CMake configuration for your build directory
2) Build `worldserver` and `authserver`

TODO: Add exact build commands for your environment (Linux, Windows, macOS, Docker).

### Cloning the Repositories

To install both the required branch of AzerothCore and the `mod-playerbots` module from source, run the following:

```bash
git clone https://github.com/mod-playerbots/azerothcore-wotlk.git --branch=Playerbot
cd azerothcore-wotlk/modules
git clone https://github.com/kambire/playerbots-reload-module.git --branch=main mod-playerbots
```

Notes:
- The folder name under `modules/` should be `mod-playerbots`.
- This repo is intended to be used as a module checkout; keep your build directory outside the source tree as recommended by AzerothCore.

### Updating
To update this module:

```bash
cd azerothcore-wotlk/modules/mod-playerbots
git fetch
git checkout main
git pull
```

If the update includes code changes, rebuild AzerothCore.

### Uninstalling
To uninstall, remove the module folder and rebuild:

```bash
rm -rf azerothcore-wotlk/modules/mod-playerbots
```

TODO: Document how to rollback SQL changes if your setup requires it.

### Build Notes (Windows + WSL)
If you build AzerothCore in WSL/Linux but edit this repository on Windows, ensure you are compiling the same checkout.
- If your compiler output paths look like `/home/user/...`, you are building a Linux/WSL copy.
- If your edits are on `D:\...`, they will not affect a build using `/home/user/...`.

TODO: Add an explicit recommended workflow (either fully WSL, or Windows-native build).

For more information, refer to the [AzerothCore Installation Guide](https://www.azerothcore.org/wiki/installation) and [Installing a Module](https://www.azerothcore.org/wiki/installing-a-module) pages.

### Docker Installation

Docker installations are considered experimental (unofficial with limited support), and previous Docker experience is recommended. To install `mod-playerbots` on Docker, first clone the required branch of AzerothCore and this module:

```bash
git clone https://github.com/mod-playerbots/azerothcore-wotlk.git --branch=Playerbot
cd azerothcore-wotlk/modules
git clone https://github.com/kambire/playerbots-reload-module.git --branch=main mod-playerbots
```

Afterwards, create a `docker-compose.override.yml` file in the `azerothcore-wotlk` directory. This override file allows for mounting the modules directory to the `ac-worldserver` service which is required for it to run. Put the following inside and save:

```yml
services:
  ac-worldserver:
    volumes:
      - ./modules:/azerothcore/modules:ro
```

Additionally, this override file can be used to set custom configuration settings for `ac-worldserver` and any modules you install as environment variables:

```yml
services:
  ac-worldserver:
    environment:
      AC_RATE_XP_KILL: "1"
      AC_AI_PLAYERBOT_RANDOM_BOT_AUTOLOGIN: "1"
    volumes:
      - ./modules:/azerothcore/modules:ro
```

For example, to double the experience gain rate per kill, take the setting `Rate.XP.Kill = 1` from [woldserver.conf](https://github.com/mod-playerbots/azerothcore-wotlk/blob/Playerbot/src/server/apps/worldserver/worldserver.conf.dist), convert it to an environment variable, and change it to the desired setting in the override file to get `AC_RATE_XP_KILL: "2"`. If you wanted to disable random bots from logging in automatically, take the `AiPlayerbot.RandomBotAutologin = 1` setting from `conf/playerbots.conf.dist` and do the same to get `AC_AI_PLAYERBOT_RANDOM_BOT_AUTOLOGIN: "0"`. For more information on how to configure Azerothcore, Playerbots, and other module settings as environment variables in Docker Compose, see the "Configuring AzerothCore in Containers" section in the [Install With Docker](https://www.azerothcore.org/wiki/install-with-docker) guide.

Before building, consider setting the database password. One way to do this is to create a `.env` file in the root `azerothcore-wotlk` directory using the [template](https://github.com/mod-playerbots/azerothcore-wotlk/blob/Playerbot/conf/dist/env.docker). This file also allows you to set the user and group Docker uses for the services in case you run into any permissions issues, which are the most common cause for Docker installation problems.

Use `docker compose up -d --build` to build and run the server. For more information, including how to create an account and taking backups, refer to the [Install With Docker](https://www.azerothcore.org/wiki/install-with-docker) page.

## Configuration
This module ships with a config template:
- `conf/playerbots.conf.dist`

Typical setup:
1) Copy `playerbots.conf.dist` into your server config directory.
2) Rename it to `playerbots.conf`.
3) Adjust settings as needed.

TODO: Document the exact config directory path for your distribution (Docker, Windows, Linux).

## Database / SQL
SQL files are provided under:
- `data/sql/`

TODO: Specify which databases are affected (`world`, `characters`, `auth`, or `playerbots`) and the recommended import/upgrade flow.

If your AzerothCore setup uses a DB assembler flow, also document how these SQL files are integrated.

## Documentation

The [Playerbots Wiki](https://github.com/mod-playerbots/mod-playerbots/wiki) contains an extensive overview of AddOns, commands, raids with programmed bot strategies, and recommended performance configurations. Please note that documentation may be incomplete or out-of-date in some sections, and contributions are welcome.

Bots are controlled via chat commands. For larger bot groups, this can be cumbersome. Because of this, community members have developed client AddOns to allow controlling bots through the in-game UI. We recommend you check out their projects listed in the [AddOns and Submodules](https://github.com/mod-playerbots/mod-playerbots/wiki/Playerbot-Addons-and-Sub%E2%80%90Modules) page.

## Troubleshooting
- **Build errors**: confirm you are compiling the same checkout you edited (see [Build Notes (Windows + WSL)](#build-notes-windows--wsl)).
- **Bots not behaving as expected**: confirm the module config is loaded and that required SQL was applied.
- **Docker**: permissions issues are the most common cause; see the Docker section above.

## Contributing

This project is still under development. We encourage anyone to make contributions, anything from pull requests to reporting issues. If you encounter any errors or experience crashes, we encourage you [report them as GitHub issues](https://github.com/mod-playerbots/mod-playerbots/issues/new?template=bug_report.md). Your valuable feedback will help us improve this project collaboratively.

If you make coding contributions, `mod-playerbots` complies with the [C++ Code Standards](https://www.azerothcore.org/wiki/cpp-code-standards) established by AzerothCore. Each Pull Request must include all test scenarios the author performed, along with their results, to demonstrate that the changes were properly verified.

We recommend joining the [Discord server](https://discord.gg/NQm5QShwf9) to make your contributions to the project easier, as a lot of active support is carried out through this server.

Please click on the "⭐" button to stay up to date and help us gain more visibility on GitHub!

## Acknowledgements

`mod-playerbots` is based on [ZhengPeiRu21/mod-playerbots](https://github.com/ZhengPeiRu21/mod-playerbots) and [celguar/mangosbot-bots](https://github.com/celguar/mangosbot-bots). We extend our gratitude to [@ZhengPeiRu21](https://github.com/ZhengPeiRu21) and [@celguar](https://github.com/celguar) for their continued efforts in maintaining the module.

Also, a thank you to the many contributors who've helped build this project:

<a href="https://github.com/mod-playerbots/mod-playerbots/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=mod-playerbots/mod-playerbots" />
</a>
