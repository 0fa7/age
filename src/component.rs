#[derive(Debug)]
pub struct Component {}

impl Component {
    pub fn update(&self) {}
}

pub struct Position2D {
    m_x: i64,
    m_y: i64,
}

impl Position2D {
    fn new(x: i64, y: i64) -> Self {
        Position2D { m_x: x, m_y: y }
    }
}

pub struct TransformComponent {
    m_position: Position2D,
}

impl TransformComponent {
    fn new() -> Self {
        TransformComponent {
            m_position: Position2D::new(0, 0),
        }
    }
}
