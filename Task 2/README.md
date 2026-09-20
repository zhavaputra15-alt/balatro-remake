# Task 2 - Core Loop Architecture (Horse Racing Game)

## Step 1 — Core Loop
1. Player chooses horse speed modifier and places a bet.
2. System evaluates horse positions and calculates race movements.
3. Reward or penalty is calculated based on placement.
4. Game state updates (round counter, player funds, horse positions).
5. Repeat until final round.

## Step 2 — Invariants
1. **Unchangeable Order**: Player action -> System resolution -> State update.
2. **Essential Components**: `GameSession` state, input processor, and reward resolver.
3. **Break Risk**: Calculating rewards before system resolution creates incorrect placements.

## Step 3 — Mutable Elements
1. **Speed Multiplier**: Base movement values of horses.
2. **Betting Reward Formula**: Calculation for winnings.
3. **Total Track Length**: Distance required to finish a race.

These are mutable because altering parameters changes balance without breaking execution structure.

## Step 4 — Reflection
The invariant structure of this horse-racing game is defined by its strict lifecycle sequence managed inside `GameSession::StartGame()`. The game loop relies on three non-negotiable phases: player decision-making, system evaluation, and state updates. This sequence forms the architectural foundation of the application and guarantees proper execution flow across rounds.

The mutable elements consist of game rules, track parameters, and reward multipliers. These include the speed calculation formulas, track length limits, betting payout ratios, and enemy/opponent AI movement speed. Modifying these components affects gameplay difficulty and balancing, but leaves the underlying loop structure intact.

If a new feature like a "Weather Condition System" were added, it would be integrated by creating a dedicated class (e.g., `WeatherEffect`) or passing a modifier strategy into `ResolveSystem()`. `GameSession` itself would remain unchanged, preserving modularity.

If the loop order were altered—such as triggering `UpdateState()` before `ResolveSystem()`—the game logic would break. Scores and rewards would be calculated from outdated positions, resulting in invalid race outcomes and broken state persistence.