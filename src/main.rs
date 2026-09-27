use age::engine::Engine;
use sdl3::event::Event;
use sdl3::keyboard::Keycode;
use sdl3::pixels::Color;
use std::time::Duration;

pub fn main() {
    let mut engine = Engine::new();
    engine.run();

    /*
        ::std::thread::sleep(Duration::new(0, 1_000_000_000u32 / 60));
    }*/
}
