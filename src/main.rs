use age::engine::Engine;

pub fn main() {
    let mut engine = Engine::new();
    engine.setup_level();
    engine.run();
}
