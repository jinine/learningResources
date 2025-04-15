---

### 🏭 **Factory Pattern**
**Purpose:** Create objects without specifying the exact class.
```ts
interface Enemy {
  attack(): void;
}

class Zombie implements Enemy {
  attack() { console.log("Zombie attack!"); }
}

class EnemyFactory {
  static createEnemy(type: string): Enemy {
    if (type === "zombie") return new Zombie();
    throw new Error("Unknown enemy type.");
  }
}

const z = EnemyFactory.createEnemy("zombie");
z.attack();
```

---

### 🔌 **Adapter Pattern**
**Purpose:** Convert one interface into another that the client expects.
```ts
class OldSystem {
  getData() { return "old data"; }
}

interface NewSystem {
  fetch(): string;
}

class Adapter implements NewSystem {
  constructor(private oldSystem: OldSystem) {}
  fetch() { return this.oldSystem.getData(); }
}
```

---

### 👑 **Singleton Pattern**
**Purpose:** Ensure a class has only one instance and provide a global access point.
```ts
class Config {
  private static instance: Config;
  private constructor() {}

  static getInstance(): Config {
    if (!Config.instance) Config.instance = new Config();
    return Config.instance;
  }
}
```

---

### 🌳 **Composite Pattern**
**Purpose:** Treat individual objects and groups of objects uniformly.
```ts
interface Component {
  operation(): void;
}

class Leaf implements Component {
  operation() { console.log("Leaf"); }
}

class Composite implements Component {
  private children: Component[] = [];

  add(child: Component) { this.children.push(child); }
  operation() { this.children.forEach(c => c.operation()); }
}
```

---

### 👀 **Observer Pattern**
**Purpose:** Let objects subscribe and react to events/changes in another object.
```ts
interface Observer {
  update(data: any): void;
}

class Subject {
  private observers: Observer[] = [];

  subscribe(obs: Observer) { this.observers.push(obs); }
  notify(data: any) { this.observers.forEach(obs => obs.update(data)); }
}
```

---

### 🧠 **Strategy Pattern**
**Purpose:** Swap out algorithms or behaviors at runtime.
```ts
interface PaymentStrategy {
  pay(amount: number): void;
}

class CreditCard implements PaymentStrategy {
  pay(amount: number) { console.log(`Paid ${amount} with credit card.`); }
}

class PaymentContext {
  constructor(private strategy: PaymentStrategy) {}
  process(amount: number) { this.strategy.pay(amount); }
}
```

---

### 🔄 **Inversion of Control (IoC)**
**Purpose:** Let a framework or container control object creation and lifecycle.
- **You don’t call the framework; the framework calls you.**
- Often implemented with **Dependency Injection**:
```ts
class Logger {
  log(msg: string) { console.log(msg); }
}

class Service {
  constructor(private logger: Logger) {}
  doWork() { this.logger.log("Working!"); }
}

// logger is injected instead of created internally
const service = new Service(new Logger());
```

---
