*This project has been created as part of the 42 curriculum by jcano-du, nfiora-d.*

## 📖 Description

**cub3D** is a project inspired by the world-famous 90s game, *Wolfenstein 3D*. The main objective of this project is to create a basic 3D engine using the **Raycasting** technique. This project is a great opportunity to explore applied mathematics, window and event management via the *miniLibX*, as well as rigorous configuration file parsing.

### Main Features

* **3D Rendering**: Functional raycasting engine.
* **Textures**: Application of different textures for walls depending on their orientation (North, South, East, West).
* **Colors**: Hexadecimal/RGB color management for the floor and ceiling.
* **Strict Parsing**: Reading and validating `.cub` format maps.
* **Movement**: Smooth player movement with wall collision detection.

---

## 🛠️ Compilation and Installation

### Prerequisites

* `gcc` or `cc` compiler
* `make`
* Environment compatible with the **miniLibX** (Linux / macOS)

### Instructions

1.  Clone the repository:
    ```bash
    git clone <your_github_or_gitea_link>
    cd cub3D
    ```

2.  Compile the project:
    ```bash
    make
    ```
    > The available Makefile rules are: `make`, `make clean`, `make fclean`, `make re`.

---

## 🚀 Usage

To launch the game, you must pass a valid `.cub` map file as an argument.

```bash
./cub3D maps/valid_map.cub
```

### In-game Controls

| Action | Key |
| :--- | :--- |
| **Move Forward** | `W` |
| **Move Backward** | `S` |
| **Strafe Left** | `A` |
| **Strafe Right** | `D` |
| **Rotate Camera Left** | `Left Arrow` (←) |
| **Rotate Camera Right** | `Right Arrow` (→) |
| **Quit Game** | `ESC` |

---

## 🗺️ Map Format (`.cub`)

The map configuration file must follow strict parsing rules:

* **Texture Identifiers**: `NO`, `SO`, `WE`, `EA` followed by the path to the texture file.
* **Colors**: `F` (Floor) and `C` (Ceiling) followed by RGB values (e.g., `220,100,0`).
* **The Map**: Composed of `0` (empty space), `1` (wall), and a starting letter (`N`, `S`, `E`, `W`) representing the player's initial position and spawning orientation. The map must be completely enclosed by walls.

---
