use sdl3::Sdl;
use sdl3::VideoSubsystem;
use sdl3::pixels::Color;
use sdl3::render::Canvas;
use sdl3::video::Window;

pub struct Engine {
    m_sdl_context: Sdl,
    m_video_subsystem: VideoSubsystem,
    m_canvas: Canvas<Window>,
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

        Engine {
            m_sdl_context: sdl_context,
            m_video_subsystem: video_subsystem,
            m_canvas: canvas,
        }
    }

    pub fn run(&mut self) {
        let mut count = 0;

        'game_loop: loop {
            self.m_canvas.set_draw_color(Color::RGB(0, 255, 255));
            self.m_canvas.clear();
            self.m_canvas.present();

            if count >= 20000 {
                break 'game_loop;
            }

            count += 1;
        }
        
    }
}
