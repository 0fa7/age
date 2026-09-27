use crate::actor::Actor;
use sdl3::EventPump;
use sdl3::Sdl;
use sdl3::VideoSubsystem;
use sdl3::event::Event;
use sdl3::keyboard::Keycode;
use sdl3::pixels::Color;
use sdl3::render::Canvas;
use sdl3::video::Window;

pub struct Engine {
    m_sdl_context: Sdl,
    m_video_subsystem: VideoSubsystem,
    m_canvas: Canvas<Window>,
    m_event_pump: EventPump,
    m_is_running: bool,
    m_actors: Vec<Actor>,
}

impl Engine {
    pub fn new() -> Self {
        let sdl_context: Sdl = sdl3::init().unwrap();
        let video_subsystem: VideoSubsystem = sdl_context.video().unwrap();
        let window: Window = video_subsystem
            .window("Another Game Engine", 2560, 1440)
            .position_centered()
            .build()
            .unwrap();
        let canvas: sdl3::render::Canvas<Window> = window.into_canvas();
        let event_pump = sdl_context.event_pump().unwrap();

        Engine {
            m_sdl_context: sdl_context,
            m_video_subsystem: video_subsystem,
            m_canvas: canvas,
            m_event_pump: event_pump,
            m_is_running: true,
            m_actors: Vec::new(),
        }
    }

    pub fn run(&mut self) {
        'game_loop: loop {
            if !self.m_is_running {
                break 'game_loop;
            }

            self.process_input();
            self.update();
            self.render();
        }
    }

    fn process_input(&mut self) {
        for event in self.m_event_pump.poll_iter() {
            match event {
                Event::Quit { .. }
                | Event::KeyDown {
                    keycode: Some(Keycode::Escape),
                    ..
                } => self.m_is_running = false,
                _ => {}
            }
        }
    }

    fn update(&self) {
        for actor in &self.m_actors {
            actor.update();
        }
    }

    fn render(&mut self) {
        self.m_canvas.set_draw_color(Color::RGB(0, 0, 255));
        self.m_canvas.clear();
        self.m_canvas.present();
    }
}
