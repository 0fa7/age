use crate::component::Component;

#[derive(Debug)]
pub struct Actor {
    pub m_id: u64,
    pub m_components: Vec<Component>,
}

impl Actor {
    pub fn new(id: u64) -> Self {
        Actor {
            m_id: id,
            m_components: Vec::new(),
        }
    }

    pub fn update(&self) {
        for component in &self.m_components {
            component.update();
        }
    }
}
